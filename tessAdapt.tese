#version 430 core
#extension GL_EXT_gpu_shader4 : enable
#define F3 0.333333333
#define G3 0.166666667

layout(triangles, equal_spacing, ccw) in;

uniform mat4 MVP;
uniform bool noise;

in vec3 tcPosition[];
in vec3 tcNormal[];
in vec4 tcColor[];
in vec2 tcTexCoord[];

out float p;
out vec3 vcNormal;
out vec4 vcColor;
out vec2 vcTexCoord;
out vec3 tePosition;


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
    f += 0.5000*noise( p ); p = m3*p*4.04;
    f += 0.2500*noise( p ); p = m3*p*4.06;
    f += 0.1250*noise( p ); p = m3*p*4.02;
    f += 0.0625*noise( p );

    return f/0.9375;
}

void main(){
    vec3 newTcPosition0 = (tcPosition[0]);
    vec3 newTcPosition1 = (tcPosition[1]);
    vec3 newTcPosition2 = (tcPosition[2]);

    if(noise){
        newTcPosition0.y = fbm(newTcPosition0)*5;
        newTcPosition1.y = fbm(newTcPosition1)*5;
        newTcPosition2.y = fbm(newTcPosition2)*5;
    }
    vec3 p0 = gl_TessCoord.x * newTcPosition0;
    vec3 p1 = gl_TessCoord.y * newTcPosition1;
    vec3 p2 = gl_TessCoord.z * newTcPosition2;
    tePosition = (p0 + p1 + p2);
    //tePosition.y = iqfBm(tePosition, 1,2,0.5);

    vec3 n0 = gl_TessCoord.x * tcNormal[0];
    vec3 n1 = gl_TessCoord.y * tcNormal[1];
    vec3 n2 = gl_TessCoord.z * tcNormal[2];
    vcNormal = normalize(n0 + n1 + n2);

    vec4 c0 = gl_TessCoord.x * tcColor[0];
    vec4 c1 = gl_TessCoord.y * tcColor[1];
    vec4 c2 = gl_TessCoord.z * tcColor[2];

/*
    c0 = vec4(1.f, 0.0, 0.0, 1.f);
    c1 = vec4(0.0, 1.f, 0.0, 1.f);
    c2 = vec4(0.0, 0.0, 1.f, 1.f);
*/
    vcColor = (c0 + c1 + c2);

    vec2 t0 = gl_TessCoord.x * tcTexCoord[0];
    vec2 t1 = gl_TessCoord.y * tcTexCoord[1];
    vec2 t2 = gl_TessCoord.z * tcTexCoord[2];
    vcTexCoord = (t0 + t1 + t2);

    p = tePosition.y;
    gl_Position = MVP * vec4(tePosition, 1.0);
}
