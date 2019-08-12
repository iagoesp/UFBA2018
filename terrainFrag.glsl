#version 430 core

 in vec3 vcNormal;
 in vec3 n;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;
in float vNoise;
in vec3 tePosition;
in vec3 tvPosition;

uniform sampler2D terra;
uniform sampler2D agua;
uniform sampler2D grama;
uniform sampler2D neve;
uniform sampler2D montanha;
uniform vec3 viewPos;
uniform int frag;
out vec4 fragColor;

 #define clamp01(x) clamp(x, 0.0, 1.0)

vec3 water = texture2D(agua, vcTexCoord).xyz;
vec3 sand = texture2D(terra, vcTexCoord).xyz;
vec3 grass = texture2D(grama, vcTexCoord).xyz;
vec3 snow = texture2D(neve, vcTexCoord).xyz;
vec3 rock = texture2D(montanha, vcTexCoord).xyz;

float weightWater;
float weightStone;
float weightGrass;

vec3 fgNormal;

 vec3 heightblend(vec3 tex1, float height1, vec3 tex2, float height2)
{
    float heightBlendFactor = 1.f;
    float height_start = max(height1, height2 - 1) - heightBlendFactor;
    float level1 = max(height1 - height_start, 0);
    float level2 = max(height2 - height_start -1, 0);
    return ((tex1 * level1) + (tex2 * level2)) / (level1 + level2);
}

 vec3 surf(vec3 tex1, float h1, vec3 tex2, float h2)
{
    vec3 t1 = tex1;
    vec3 t2 = tex2;
    return heightblend (t1, h1, t2, h2);
}

#define clamp01(x) clamp(x, 0.0, 1.0)


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

//const mat2 m2 = mat2(1.6,-1.2,1.2,1.6);
const mat2 m2 = mat2(0.8,-0.6,0.6,0.8);

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

float SC = 20.f;

float detailH( in vec2 x )
{
    float d = 0.0;//50.0*texture( iChannel2, x*0.03/SC, 0.0 ).x;
    return d + 0.5*noise(x*2.0/SC);
}

float detailM( in vec2 x )
{
    float d = 0.0;//50.0*texture( iChannel2, x*0.03/SC, 0.0 ).x;
    return d;
}

float terrainH( in vec2 x )
{
	vec2  p = x*0.003/SC;
    float a = 0.0;
    float b = 1.0;
	vec2  d = vec2(0.0);
    for( int i=0; i<15; i++ )
    {
        vec3 n = noised(p);
        d += n.yz;
        a += b*n.x/(1.0+dot(d,d));
		b *= 0.5;
        p = m2*p*2.0;
    }

    float de = detailH(x);
	return SC*100.0*a - de;
}

float terrainM( in vec2 x )
{
	vec2  p = x*0.003/SC;
    float a = 0.0;
    float b = 1.0;
	vec2  d = vec2(0.0);
    for( int i=0; i<9; i++ )
    {
        vec3 n = noised(p);
        d += n.yz;
        a += b*n.x/(1.0+dot(d,d));
		b *= 0.5;
        p = m2*p*2.0;
    }
	return SC*100.0*a - detailH(x);
}

float terrainL( in vec2 x )
{
	vec2  p = x*0.003/SC;
    float a = 0.0;
    float b = 1.0;
	vec2  d = vec2(0.0);
    for( int i=0; i<7; i++ )
    {
        vec3 n = noised(p);
        d += n.yz;
        a += b*n.x/(1.0+dot(d,d));
		b *= 0.5;
        p = m2*p*2.0;
    }

	return SC*100.0*a;
}

float interesct( in vec3 ro, in vec3 rd, in float tmin, in float tmax )
{
  float t = tmin;
	for( int i=0; i<256; i++ )
	{
        vec3 pos = ro + t*rd;
		float h = pos.y - terrainM( pos.xz );
		if( h<(0.002*t) || t>tmax ) break;
		t += 0.5*h;
	}

	return t;
}

float plaIntersect( in vec3 ro, in vec3 rd, in vec4 p )
{
    return -(dot(ro,p.xyz)+p.w)/dot(rd,p.xyz);
}

vec3 calcNormal( in vec3 pos, float t )
{
    vec2  eps = vec2( 0.002*t, 0.0 );
    return normalize( vec3( terrainH(pos.xz-eps.xy) - terrainH(pos.xz+eps.xy),
                            2.0*eps.x,
                            terrainH(pos.xz-eps.yx) - terrainH(pos.xz+eps.yx) ) );
}

vec3 render(vec3 ro, vec3 rd){
  vec3 light1 = normalize( vec3(-0.8,0.4,-0.3) );
    // bounding plane
    float tmin = 1.0;
    float tmax = 1000.0;
    //float tmax = 10000*tePosition.y; //minha Adap
#if 1
    float maxh = 100.0;//*tePosition.y;//300.0*SC;
    float tp = (maxh-ro.y)/rd.y;
    if( tp>0.0 )
    {
        if( ro.y>maxh ) tmin = max( tmin, tp );
        else            tmax = min( tmax, tp );
    }
#endif
	float sundot = clamp(dot(rd,light1),0.0,1.0);
	vec3 col;
  float t = interesct( ro, rd, tmin, tmax );
  if( t<=tmax)
    {
        // mountains
		vec3 pos = tePosition*ro + t*rd;
    vec3 nor = calcNormal( pos, t );
    //nor = normalize( nor + 0.5*( vec3(-1.0,0.0,-1.0) + vec3(2.0,1.0,2.0)*texture(iChannel1,0.01*pos.xz).xyz) );
    vec3 ref = reflect( rd, nor );
    float fre = clamp( 1.0+dot(rd,nor), 0.0, 1.0 );

         //rock
		float r = noise((7.0/SC)*pos.xz/256.0);
    col = (r*0.25+0.75)*0.9*mix( vec3(0.08,0.05,0.03), vec3(0.10,0.09,0.08),
                                     noise(0.00007*vec2(pos.x,pos.y*48.0)/SC));
		col = mix( col, 0.20*vec3(0.45,.30,0.15)*(0.50+0.50*r),smoothstep(0.70,0.9,nor.y) );
    col = mix( col, 0.15*vec3(0.30,.30,0.10)*(0.25+0.75*r),smoothstep(0.95,1.0,nor.y) );

		// snow
    float h = smoothstep(55.0,200.0,pos.y + 25.0*vNoise );  //altura
    float e = smoothstep(1.0-0.5*h,1.0-0.1*h,nor.y);        //transpar�ncia
    float o = 0.3 + 0.7*smoothstep(0.0,0.1,nor.x+h*h);      //gama
    float s = h*e*o;
    col = mix( col, 0.29*vec3(0.62,0.65,0.7), smoothstep( 0.1, 0.9, s ) );

         // lighting
    float amb = clamp(0.5+0.5*nor.y,0.0,1.0);
		float dif = clamp( dot( light1, nor ), 0.0, 1.0 );
		float bac = clamp( 0.2 + 0.8*dot( normalize( vec3(-light1.x, 0.0, light1.z ) ), nor ), 0.0, 1.0 );
		float sh = 1.0; if( dif>=0.0001 )
		sh = softShadow(pos+light1*20.0,light1);

		vec3 lin  = vec3(0.0);
		lin += dif*vec3(7.00,5.00,3.00)*vec3( sh, sh*sh*0.5+0.5*sh, sh*sh*0.8+0.2*sh );
		lin += amb*vec3(0.40,0.60,0.80)*1.2;
        lin += bac*vec3(0.40,0.50,0.60);
		col *= lin;

        col += s*0.1*pow(fre,4.0)*vec3(7.0,5.0,3.0)*sh * pow( clamp(dot(light1,ref), 0.0, 1.0),16.0);
        col += s*0.1*pow(fre,4.0)*vec3(0.4,0.5,0.6)*smoothstep(0.0,0.6,ref.y);

		// fog
        //float fo = 1.0-exp(-0.000004*t*t/(SC*SC) );
    float fo = 1.0-exp(-0.001*t/SC );
    vec3 fco = 0.7*vec3(0.5,0.7,0.9) + 0.1*vec3(1.0,0.8,0.5)*pow( sundot, 4.0 );
    col = mix( col, fco, fo );

        // sun scatter
		col += 0.3*vec3(1.0,0.8,0.4)*pow( sundot, 8.0 )*(1.0-exp(-0.002*t/SC));
	}

    // gamma
	col = pow(col,vec3(0.4545));

	return col;
}




void main(){
  vec3 X = dFdx(tePosition);
  vec3 Y = dFdy(tePosition);
  vec3 normal2 = normalize(cross(X,Y));
  //normal2 = cross(normalize(tePosition),vec3(0,1,0));

  vec3 fNormal = normalize(cross(normal2, normalize(n)));
  fgNormal = normalize(normal2);
  vec4 col;
  if(frag == 2){
    vec3 vertical = vec3(0, 1, 0);

    float angleDiff = abs(dot(fgNormal.xyz, vertical));
    float pureRock = 0.4f;
    float lerpRock = 0.9f;
    float coef = 1.0 - smoothstep(pureRock, lerpRock, angleDiff);
    grass = mix(grass, rock, coef);
    snow = mix(snow, rock, coef);
    coef = smoothstep(0.8, 9., angleDiff);
    grass = mix(grass, snow, coef);


    float snow_height = 4.0f;
    float grass_height = 2.4;
    float sand_height = 0.8f;
    float mix_zone = 0.4f;
    vec3 kd = vec3(1.0);

    float gHeight = tePosition.y;
    if (gHeight > snow_height + mix_zone){
        kd = snow;
    } else if (gHeight > snow_height - mix_zone) {
        float coef = (gHeight-(snow_height - mix_zone))/(2.0 * mix_zone);
        kd = mix(grass, snow, coef);
    } else if (gHeight > grass_height + mix_zone){
        kd = grass;
    } else if (gHeight > grass_height - mix_zone){
        float coef = (gHeight-(grass_height - mix_zone))/(2.0 * mix_zone);
        kd = mix(sand, grass, coef);
    } else if (gHeight > sand_height + mix_zone){
        kd = sand;
    } else if (gHeight > sand_height - mix_zone){
        float coef = (gHeight-(sand_height - mix_zone))/(2.0 * mix_zone);
        kd = mix(water, sand, coef);
    }else{
      kd= water;
    }

    col = vec4(kd, 1.0f);

  }
  else if(frag == 1){
      float height = p;
    vec4 blank = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
    vec4 blue = vec4 ( 0.0f, 0.0f, 1.0f, 1.0f );
    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );

    const float leveli1 = -2.f;
    const float level0 = 0.f;
    const float level1 = 2.f;
    const float level2 = 4.f;
    const float level3 = 6.f;
    const float level4 = 8.f;

    if(height <= leveli1){
      vTexColor = vec4(surf(water, leveli1, grass , height), 1.f);
    }
    else if(height > leveli1 && height <= level0){
      vTexColor = vec4(surf(water, leveli1, grass , height), 1.f);
    }
    else if(height > level0 && height <= level2){
      vTexColor = vec4(surf(grass, level0, sand , height), 1.f);
    }
    else if(height > level2 && height <= level3){
      vTexColor = vec4(surf(sand, level2, rock, height), 1.f);
    }
    else if(height > level3){
      vTexColor = vec4(surf(rock , level3 , snow , height-1), 1.f);
    }

    col = vTexColor;


  }
  else if(frag == 0){
    vec2 xy = -1.0 + 2.0*gl_FragCoord.xy/(vec2(1024,1280));
    vec2 s = xy*(vec2(1024/1280,1.f));
    vec3 ro = vec3(100, 50, 100);
    vec3 rd = normalize(vec3(s,2.f));
    //ro.y += (1.5 * SC) + terrainL(ro.xz);

    col = vec4(render(ro, rd), 1.f);
  }
  else{
    col = vec4(fNormal, 1.f);
  }
  fragColor = col;
}

