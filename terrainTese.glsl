#version 430 core
#extension GL_EXT_gpu_shader4 : enable
#define F3 0.333333333
#define G3 0.166666667

layout(triangles, equal_spacing, ccw) in;

uniform mat4 P;
uniform mat4 V;
uniform mat4 MVP;
uniform int oct;
uniform float lac;
uniform bool noised;

in vec3 tcPosition[];
in vec4 tcColor[];
in vec2 tcTexCoord[];

out vec3 vPosition;
out vec4 vColor;
out vec2 vTexCoord;
out float vNoise;
out vec3 vNormal;

float noiseGlobal;

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

//vec3 noise3( in vec2 x )
//{
//    vec2 p = floor(x);
//    vec2 f = fract(x);
//    vec2 u = f*f*(3.0-2.0*f);
//	float a = texture(iChannel0,(p+vec2(0.5,0.5))/256.0,-100.0).x;
//	float b = texture(iChannel0,(p+vec2(1.5,0.5))/256.0,-100.0).x;
//	float c = texture(iChannel0,(p+vec2(0.5,1.5))/256.0,-100.0).x;
//	float d = texture(iChannel0,(p+vec2(1.5,1.5))/256.0,-100.0).x;
//	return vec3(a+(b-a)*u.x+(c-a)*u.y+(a-b-c+d)*u.x*u.y,
//				6.0*f*(1.0-f)*(vec2(b-a,c-a)+(a-b-c+d)*u.yx));
//}
//
//vec3 fbm3(vec3 x, int octaves )
//{
//    float f = 1.98;  // could be 2.0
//    float s = 0.49;  // could be 0.5
//    float a = 0.0;
//    float b = 0.5;
//    vec3  d = vec3(0.0);
//    mat3  m = mat3(1.0,0.0,0.0,
//    0.0,1.0,0.0,
//    0.0,0.0,1.0);
//    for( int i=0; i < octaves; i++ )
//    {
//        vec3 n = noise3(x);
//        a += b*n.x;          // accumulate values
//        d += b*m*n.yzw;      // accumulate derivatives
//        b *= s;
//        x = f*m3*x;
//        m = f*m3i*m;
//    }
//    return vec4( a, d );
//}

void main(){
    vec3 tcPos0 = (tcPosition[0]);
    vec3 tcPos1 = (tcPosition[1]);
    vec3 tcPos2 = (tcPosition[2]);

    vec3 p0 = gl_TessCoord.x * tcPos0;
    vec3 p1 = gl_TessCoord.y * tcPos1;
    vec3 p2 = gl_TessCoord.z * tcPos2;
    vPosition = (p0 + p1 + p2);

    vNormal = normalize(cross(tcPos2 - tcPos0, tcPos1 - tcPos0));

    noiseGlobal = noise(vPosition);
    vNoise = fbm(vPosition);
    vPosition.y = vPosition.y + vNoise;
    vNormal = normalize(vNormal*vNoise);


    vec4 c0 = gl_TessCoord.x * tcColor[0];
    vec4 c1 = gl_TessCoord.y * tcColor[1];
    vec4 c2 = gl_TessCoord.z * tcColor[2];
    vColor = (c0 + c1 + c2);

    vec2 t0 = gl_TessCoord.x * tcTexCoord[0];
    vec2 t1 = gl_TessCoord.y * tcTexCoord[1];
    vec2 t2 = gl_TessCoord.z * tcTexCoord[2];
    vTexCoord = (t0 + t1 + t2);

    gl_Position = MVP * vec4(vPosition, 1.0);
}
