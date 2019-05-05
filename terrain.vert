#version 430 core
#extension GL_EXT_gpu_shader4 : enable
#define F2 0.366025403
#define G2 0.211324865

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

float h;
out vec3 vNormal;
out vec4 vColor;
out vec2 TexCoord;

out vec3 vPosition;

uniform bool pos2;
uniform bool noise;

mat2 m2 = mat2(1.6,-1.2,1.2,1.6);
mat3 m3 = mat3( 0.00,  0.80,  0.60,
              -0.80,  0.36, -0.48,
              -0.60, -0.48,  0.64 );
mat3 m3i = inverse(m3);


float hash(float n) { return fract(sin(n) * 1e4); }
float hash(vec2 p) { return fract(1e4 * sin(17.0 * p.x + p.y * 0.1) * (0.1 + abs(sin(p.y * 13.0 + p.x)))); }
float hash3(vec3 p)
{
    p  = 50.0*fract( p*0.3183099 + vec3(0.71,0.113,0.419));
    return -1.0+2.0*fract( p.x*p.y*p.z*(p.x+p.y+p.z) );
}

float noise2f(vec2 x) {
	vec2 i = floor(x);
	vec2 f = fract(x);

	// Four corners in 2D of a tile
	float a = hash(i);
	float b = hash(i + vec2(1.0, 0.0));
	float c = hash(i + vec2(0.0, 1.0));
	float d = hash(i + vec2(1.0, 1.0));

	vec2 u = f * f * (3.0 - 2.0 * f);
	return mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

float noise3f(vec3 x )
{
    vec3 p = floor(x);
    vec3 f = fract(x);

    f = f*f*(3.0-2.0*f);

    float n = p.x + p.y*57.0 + 113.0*p.z;

    float res = mix(mix(mix( hash(n+  0.0), hash(n+  1.0),f.x),
                        mix( hash(n+ 57.0), hash(n+ 58.0),f.x),f.y),
                    mix(mix( hash(n+113.0), hash(n+114.0),f.x),
                        mix( hash(n+170.0), hash(n+171.0),f.x),f.y),f.z);
    return res;
}

vec3 noise23(vec2 x ){
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

vec4 noise34(vec3 x )
{
    vec3 p = floor(x);
    vec3 w = fract(x);

    vec3 u = w*w*w*(w*(w*6.0-15.0)+10.0);
    vec3 du = 30.0*w*w*(w*(w-2.0)+1.0);

    float a = hash3( p+vec3(0,0,0) );
    float b = hash3( p+vec3(1,0,0) );
    float c = hash3( p+vec3(0,1,0) );
    float d = hash3( p+vec3(1,1,0) );
    float e = hash3( p+vec3(0,0,1) );
    float f = hash3( p+vec3(1,0,1) );
    float g = hash3( p+vec3(0,1,1) );
    float h = hash3( p+vec3(1,1,1) );

    float k0 =   a;
    float k1 =   b - a;
    float k2 =   c - a;
    float k3 =   e - a;
    float k4 =   a - b - c + d;
    float k5 =   a - c - e + g;
    float k6 =   a - b - e + f;
    float k7 = - a + b + c - d + e - f - g + h;

    return vec4( -1.0+2.0*(k0 + k1*u.x + k2*u.y + k3*u.z + k4*u.x*u.y + k5*u.y*u.z + k6*u.z*u.x + k7*u.x*u.y*u.z),
                      2.0* du * vec3( k1 + k4*u.y + k6*u.z + k7*u.y*u.z,
                                      k2 + k5*u.z + k4*u.x + k7*u.z*u.x,
                                      k3 + k6*u.x + k5*u.y + k7*u.x*u.y ) );
}

float fbm(vec2 p){
    float f = 0.0;
    f += 0.5000*noise2f( p ); p = m2*p*2.02;
    f += 0.2500*noise2f( p ); p = m2*p*2.03;
    f += 0.1250*noise2f( p ); p = m2*p*2.01;
    f += 0.0625*noise2f( p );

    return f/0.9375;
}

float fbm( vec3 p )
{
    float f = 0.0;

    f += 0.5000*noise3f( p ); p = m3*p*2.02;
    f += 0.2500*noise3f( p ); p = m3*p*2.03;
    f += 0.1250*noise3f( p ); p = m3*p*2.01;
    f += 0.0625*noise3f( p );

    return f/0.9375;
}

vec4 fbm34(vec3 x)
{
    float f = 1.98;  // could be 2.0
    float s = 0.49;  // could be 0.5
    float a = 0.0;
    float b = 0.5;
    vec3  d = vec3(0.0);
    mat3  m = mat3(1.0,0.0,0.0,
                   0.0,1.0,0.0,
                   0.0,0.0,1.0);
    for( int i=0; i < 30; i++ )
    {
        vec4 n = noise34(x);
        a += b*n.x;          // accumulate values
        d += b*m*n.yzw;      // accumulate derivatives
        b *= s;
        x = f*m3*x;
        m = f*m3i*m;
    }
    return vec4( a, d );
}

float terrain(vec2 x )
{
	vec2  p = x*0.003;
    float a = 0.0;
    float b = 1.0;
	vec2  d = vec2(0.0);
    for(int i=0;i<5; i++)
    {
        vec3 n = noise23(p);
        d += n.yz;
        a += b*n.x/(1.0+dot(d,d));
		b *= 0.5;
        p = m2*p;
    }

    return 140.0*a;
}

void main(){
    vec4 h4;
	TexCoord    = vec2(aTexCoord.x, aTexCoord.y);

    if(pos2)
        vPosition 	=  position;
    else{
        vec2 posVec2    = vec2(position.x, position.z);
        h               = fbm (position);


        vPosition 	    =  vec3(posVec2.x, h, posVec2.y);
    }
    vNormal     = vPosition;
    vNormal     = normalize(vPosition);

//    vColor.r 	= 1.f;//h*3 / 3.0;    vColor.g 	= 0.0;    vColor.b 	= 0.0;//1.0 - h*2 / 3.0;    vColor.a 	= 1.0f;
    gl_Position = vec4(vPosition, 1.f);

}
