#version 430 core
#extension GL_EXT_gpu_shader4 : enable
#define F2 0.366025403
#define G2 0.211324865

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vPosition;
out vec4 vColor;
out vec2 vTexCoord;

out float vNoise;
out vec3 vNormal;

out vec3 normalVertex;

uniform bool CPUnoise;
uniform mat4 MVP;

float hash(float n) { return fract(sin(n) * 1e4); }
float hash(vec2 p) { return fract(1e4 * sin(17.0 * p.x + p.y * 0.1) * (0.1 + abs(sin(p.y * 13.0 + p.x)))); }

float noise(vec3 x) {
	const vec3 step = vec3(110, 241, 171);

	vec3 i = floor(x);
	vec3 f = fract(x);

	// For performance, compute the base input to a 1D hash from the integer part of the argument and the
	// incremental change to the 1D based on the 3D -> 1D wrapping
    float n = dot(i, step);

	vec3 u = f * f * (3.0 - 2.0 * f);
	return mix(mix(mix( hash(n + dot(step, vec3(0, 0, 0))), hash(n + dot(step, vec3(1, 0, 0))), u.x),
                   mix( hash(n + dot(step, vec3(0, 1, 0))), hash(n + dot(step, vec3(1, 1, 0))), u.x), u.y),
               mix(mix( hash(n + dot(step, vec3(0, 0, 1))), hash(n + dot(step, vec3(1, 0, 1))), u.x),
                   mix( hash(n + dot(step, vec3(0, 1, 1))), hash(n + dot(step, vec3(1, 1, 1))), u.x), u.y), u.z);
}

const mat3 m3  = mat3( 0.00,  0.80,  0.60,
                      -0.80,  0.36, -0.48,
                      -0.60, -0.48,  0.64 );

float fbm( vec3 p ){
    float f = 0.0;
    f += 0.5000*noise( p ); p = m3*p*2.02;
    f += 0.2500*noise( p ); p = m3*p*2.03;
    f += 0.1250*noise( p ); p = m3*p*2.01;
    f += 0.0625*noise( p );

    return f/0.9375;
}

float ridgedNoise(in vec3 p, int octaves, float H, float gain, float amplitude, float frequency, float persistence, float offset)
{
  float total = 0.f;
  float exponent = pow(amplitude, -H);
  for(int i=0;i<octaves;i++)
  {
    total += offset-(((1.0 - abs(noise(p * frequency))) * 2.0 - 1.0) * amplitude*exponent);
    frequency	*= gain;
    amplitude *= gain;
  }
  return total;
}


void main(){
  vTexCoord    = vec2(aTexCoord.x, aTexCoord.y);
  vPosition   = position - vec3(0,12,0);
  vNoise = 0.f;
  int i = 1;
  for(i; i < 6; i++)
      vNoise 	  += fbm(vPosition*i*10)*5;
    vPosition.y += vNoise;
  gl_Position =  vec4(vPosition, 1.f);
}
