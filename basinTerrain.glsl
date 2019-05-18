#version 430 core
#extension GL_EXT_gpu_shader4 : enable
#define F2 0.366025403
#define G2 0.211324865

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vPosition;
out vec3 vNormal;
out vec4 vColor;
out float h;

uniform mat4 MVP;

const mat2 m = mat2(0.8,-0.6,0.6,0.8);

float hash( float n )
{
  return fract(sin(n)*43758.5453123);
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

float terrain(vec2 p )
{
    float a = 0.0;
    float b = 1.0;
    vec2  d = vec2(0.0);
    for( int i=0; i<15; i++ )
    {
        vec3 n = noised(p);
        d += n.yz;
        a += b*n.x/(1.0+dot(d,d));
        b *= 0.5;
        p = m*p*2.0;
    }
    return a;
}

void main(){
  h           = terrain (position.xz);
  vPosition   = position;
  vPosition.y = h;
  vColor = vec4(1, 0, 0, 1);
  vNormal = normalize (vPosition);

  gl_Position = MVP * vec4(vPosition, 1.f);
}
