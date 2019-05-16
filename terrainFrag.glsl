#version 430 core

in vec3 vcNormal;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;
in float vNoise;
in vec3 tePosition;
in vec3 tvPosition;

uniform sampler2D terra;
uniform sampler2D agua;
uniform sampler2D grama;
uniform sampler2D snow;
uniform sampler2D mountain;
uniform vec3 viewPos;

out vec4 fragColor;

#define clamp01(x) clamp(x, 0.0, 1.0)

vec4 texAgua = texture2D(agua, vcTexCoord);
vec4 texTerra = texture2D(terra, vcTexCoord);
vec4 texGrama = texture2D(grama, vcTexCoord);
vec4 texSnow = texture2D(snow, vcTexCoord);
vec4 texMountain = texture2D(mountain, vcTexCoord);

float weightWater;
float weightStone;
float weightGrass;

vec3 heightblend(vec3 tex1, float height1, vec3 tex2, float height2)
{
    float heightBlendFactor = 1.f;
    float height_start = max(height1, height2 - 1) - heightBlendFactor;
    float level1 = max(height1 - height_start, 0);
    float level2 = max(height2 - height_start -1, 0);
    return ((tex1 * level1) + (tex2 * level2)) / (level1 + level2);
}

vec3 surf(vec4 tex1, float h1, vec4 tex2, float h2)
{
    vec3 t1 = tex1.rgb;
    vec3 t2 = tex2.rgb;
    return heightblend (t1, h1, t2, h2);
}


float softShadow(vec3 ro, vec3 rd )
{
    float res = 1.0;
    float t = 0.001;
	  for( int i=0; i<80; i++ ){
      vec3  p = ro + t*rd;
      float h = p.y - vNoise;
		  res = min( res, 16.0*h/t );
		  t += h;
		  if( res<0.001 ||p.y>(200.0) )
		    break;
	}
	return clamp( res, 0.0, 1.0 );
}

float hash( float n )
{
  return fract(sin(n)*43758.5453123);
}

float noise( in vec2 x )
{
  vec2 p = floor(x);
  vec2 f = fract(x);

  f = f*f*(3.0-2.0*f);

  float n = p.x + p.y*57.0;

  float res = mix(mix( hash(n+  0.0), hash(n+  1.0),f.x),
    mix( hash(n+ 57.0), hash(n+ 58.0),f.x),f.y);

  return res;
}

const mat2 m2 = mat2(1.6,-1.2,1.2,1.6);

float fbm( vec2 p )
{
  float f = 0.0;

  f += 0.5000*noise( p ); p = m2*p*2.02;
  f += 0.2500*noise( p ); p = m2*p*2.03;
  f += 0.1250*noise( p ); p = m2*p*2.01;
  f += 0.0625*noise( p );

  return f/0.9375;
}


vec3 noised( in vec2 x )
{
  vec2 p = floor(x);
  vec2 f = fract(x);

  vec2 u = f*f*(3.0-2.0*f);

  float n = p.x + p.y*57.0;

  float a = hash(n+  0.0);
  float b = hash(n+  1.0);
  float c = hash(n+ 57.0);
  float d = hash(n+ 58.0);
  return vec3(a+(b-a)*u.x+(c-a)*u.y+(a-b-c+d)*u.x*u.y,
    30.0*f*f*(f*(f-2.0)+1.0)*(vec2(b-a,c-a)+(a-b-c+d)*u.yx));

}

float terrain2( in vec2 x )
{
  vec2  p = x*0.003;
  float a = 0.0;
  float b = 1.0;
  vec2  d = vec2(0.0);
  for( int i=0; i<14; i++ )
  {
    vec3 n = noised(p);
    d += n.yz;
    a += b*n.x/(1.0+dot(d,d));
    b *= 0.5;
    p=m2*p;
  }

  return 140.0*a;
}

void main() {
  vec3 normal = normalize(vcNormal);
  vec3 light1 = normalize( vec3(30.f, 30.f, 30.f) );

  //rock
  float count = 15;
  float r = noise(tePosition.xz*count);
  vec3 col = (r*0.25+0.75)*0.9*mix( vec3(0.08,0.05,0.03), vec3(0.10,0.09,0.08), clamp(terrain2( vec2(tePosition.x,tePosition.y*48.0))/200.0,0.0,1.0));
  col = mix( col, 0.20*vec3(0.45,.30,0.15)*(0.50+0.50*r),smoothstep(0.70,0.9,normal.y) );
  col = mix( col, 0.15*vec3(0.30,.30,0.10)*(0.25+0.75*r),smoothstep(0.95,1.0,normal.y) );
  col *=0.9;

  // snow
  float h = smoothstep(55.0,80.0, p + 25.0*vNoise );
  float e = smoothstep(1.0-0.5*h,1.0-0.1*h,normal.y);
  float o = 0.3 + 0.7*smoothstep(0.0,0.1,normal.x+h*h);
  float s = h*e*o;
  col = mix( col, 0.29*vec3(0.62,0.65,0.7), smoothstep( 0.1, 0.9, s ) );

  // lighting
  float amb = clamp(0.5+0.5*normal.y,0.0,1.0);
  float dif = clamp( dot( light1, normal ), 0.0, 1.0 );
  float bac = clamp( 0.2 + 0.8*dot( normalize( vec3(-light1.x, 0.0, light1.z ) ), normal ), 0.0, 1.0 );
  float sh = 1.0;
  if( dif>=0.0001 )
    sh = softShadow(tePosition+light1*0.05, light1);

  vec3 lin  = vec3(0.0);
  lin += dif*vec3(7.00,5.00,3.00)*1.3*vec3( sh, sh*sh*0.5+0.5*sh, sh*sh*0.8+0.2*sh );
  lin += amb*vec3(0.40,0.60,1.00)*1.2;
  lin += bac*vec3(0.40,0.50,0.60);
  col *= lin;


  col = pow(col,vec3(0.45));

  col = col*0.6 + 0.4*col*col*(3.0-2.0*col);
  col *= 0.7;

  float dist = length(light1 - tvPosition);
  vec3 L = normalize( light1 - tvPosition);
  vec3 V = normalize( viewPos - tePosition);
  float difuza = max(0.1, dot(L, normal));

  //difuza = difuza * (1.0 / (1.0 + (0.25 * dist * dist)));

  vec3 Kd = vec3(0.50,0.50,0.50);
  Kd = Kd * 0.5 * difuza ;
  col = col + Kd ;

  //col = sqrt(col);
  fragColor = vec4(col, 1.f);
}

//void main(){
//    float height = p;
//    vec4 blank = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
//    vec4 blue = vec4 ( 0.0f, 0.0f, 1.0f, 1.0f );
//    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
//
//    const float leveli1 = -2.f;
//    const float level0 = 0.f;
//	const float level1 = 2.f;
//	const float level2 = 4.f;
//	const float level3 = 6.f;
//	const float level4 = 8.f;
//
//	if(height <= leveli1){
//        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
//	}
//	else if(height > leveli1 && height <= level0){
//        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
//	}
//	else if(height > level0 && height <= level2){
//        vTexColor = vec4(surf(texGrama, level0, texTerra , height), 1.f);
//    }
//    else if(height > level2 && height <= level3){
//        vTexColor = vec4(surf(texTerra, level2, texMountain, height), 1.f);
//    }
//    else if(height > level3){
//        vTexColor = vec4(surf(texMountain , level3 , texSnow , height-1), 1.f);
//    }
//
//    vec4 vFinalTexColor;
//        //vFinalTexColor= vcColor;
//        vFinalTexColor = vTexColor;
//
//   	fragColor = vFinalTexColor;
//}
