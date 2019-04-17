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

uniform bool CPUnoise;
uniform bool noise;

float hash(float n) { return fract(sin(n) * 1e4); }
float hash(vec2 p) { return fract(1e4 * sin(17.0 * p.x + p.y * 0.1) * (0.1 + abs(sin(p.y * 13.0 + p.x)))); }

float noised(vec2 x) {
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

vec3 noised3(vec2 x)
{
    vec2 f = fract(x);
    vec2 u = f*f*(3.0-2.0*f);

    // texel fetch version
    vec2 p = vec2(floor(x));
    float a = hash(p+vec2(0,0));
	float b = hash(p+vec2(1,0));
	float c = hash(p+vec2(0,1));
	float d = hash(p+vec2(1,1));

	return vec3(a+(b-a)*u.x+(c-a)*u.y+(a-b-c+d)*u.x*u.y,
				6.0*f*(1.0-f)*(vec2(b-a,c-a)+(a-b-c+d)*u.yx));
}

const mat2 m2 = mat2(0.8,-0.6,0.6,0.8);

float fbm(vec2 p){
    float f = 0.0;
    f += 0.5000*noised( p ); p = m2*p*4.04;
    f += 0.2500*noised( p ); p = m2*p*4.06;
    f += 0.1250*noised( p ); p = m2*p*4.02;
    f += 0.0625*noised( p );

    return f/0.9375;
}

void main(){
	TexCoord    = vec2(aTexCoord.x, aTexCoord.y);

    if(CPUnoise)
        vPosition 	=  position;
    else{
        vec2 posVec2    = vec2(position.x, position.z);
        h               = fbm (posVec2)*10 - 5;
        vPosition 	    =  vec3(posVec2.x, h, posVec2.y);
    }
    vNormal     = vPosition;
    vNormal     = normalize(vNormal);

//    vColor.r 	= 1.f;//h*3 / 3.0;    vColor.g 	= 0.0;    vColor.b 	= 0.0;//1.0 - h*2 / 3.0;    vColor.a 	= 1.0f;
    gl_Position = vec4(vPosition, 1.f);

}
