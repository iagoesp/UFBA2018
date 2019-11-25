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
//uniform bool noised;

in vec3 tcPosition[];
in vec4 tcColor[];
in vec2 tcTexCoord[];
in vec3 tcNormal[];

out vec3 tePosition;
out vec4 teColor;
out vec2 teTexCoord;

out vec3 upNormal;

//float hash1( vec2 p )
//{
//    p  = 50.0*fract( p*0.3183099 );
//    return fract( p.x*p.y*(p.x+p.y) );
//}
//
//vec3 noised( in vec2 x )
//{
//    vec2 p = floor(x);
//    vec2 w = fract(x);
//
//    vec2 u = w*w*w*(w*(w*6.0-15.0)+10.0);
//    vec2 du = 30.0*w*w*(w*(w-2.0)+1.0);
//
//    float a = hash1(p+vec2(0,0));
//    float b = hash1(p+vec2(1,0));
//    float c = hash1(p+vec2(0,1));
//    float d = hash1(p+vec2(1,1));
//
//    float k0 = a;
//    float k1 = b - a;
//    float k2 = c - a;
//    float k4 = a - b - c + d;
//
//    return vec3( -1.0+2.0*(k0 + k1*u.x + k2*u.y + k4*u.x*u.y),
//                      2.0* du * vec2( k1 + k4*u.y,
//                                      k2 + k4*u.x ) );
//}
//
//
//const mat3 m3  = mat3( 0.00,  0.80,  0.60,
//                      -0.80,  0.36, -0.48,
//                      -0.60, -0.48,  0.64 );
//const mat3 m3i = mat3( 0.00, -0.80, -0.60,
//                       0.80,  0.36, -0.48,
//                       0.60, -0.48,  0.64 );
//const mat2 m2 = mat2(  0.80,  0.60,
//                      -0.60,  0.80 );
//const mat2 m2i = mat2( 0.80, -0.60,
//                       0.60,  0.80 );
//
//vec3 fbmd_9( in vec2 x )
//{
//    float f = 1.9;
//    float s = 0.55;
//    float a = 0.0;
//    float b = 0.5;
//    vec2  d = vec2(0.0);
//    mat2  m = mat2(1.0,0.0,0.0,1.0);
//    for( int i=0; i<9; i++ )
//    {
//        vec3 n = noised(x);
//        a += b*n.x;          // accumulate values
//        d += b*m*n.yz;       // accumulate derivatives
//        b *= s;
//        x = f*m2*x;
//        m = f*m2i*m;
//    }
//	return vec3( a, d );
//}
//
//vec2 smoothstepd( float a, float b, float x)
//{
//	if( x<a ) return vec2( 0.0, 0.0 );
//	if( x>b ) return vec2( 1.0, 0.0 );
//    float ir = 1.0/(b-a);
//    x = (x-a)*ir;
//    return vec2( x*x*(3.0-2.0*x), 6.0*x*(1.0-x)*ir );
//}
//
//vec4 terrainMapD( in vec2 p )
//{
//	const float sca = 0.0010;
//    const float amp = 300.0;
//    p *= sca;
//    vec3 e = fbmd_9( p + vec2(1.0,-2.0) );
//    vec2 c = smoothstepd( -0.08, -0.01, e.x );
//	e.x = e.x + 0.15*c.x;
//	e.yz = e.yz + 0.15*c.y*e.yz;
//    e.x *= amp;
//    e.yz *= amp*sca;
//    return vec4( e.x, normalize( vec3(-e.y,1.0,-e.z) ) );
//}
//
//vec3 terrainNormal( in vec2 pos )
//{
//#if 1
//    return terrainMapD(pos).yzw;
//#else
//    vec2 e = vec2(0.03,0.0);
//	return normalize( vec3(terrainMap(pos-e.xy).x - terrainMap(pos+e.xy).x,
//                           2.0*e.x,
//                           terrainMap(pos-e.yx).x - terrainMap(pos+e.yx).x ) );
//#endif
//}

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

void main(){
    vec3 p0 = gl_TessCoord.x * tcPosition[0];
    vec3 p1 = gl_TessCoord.y * tcPosition[1];
    vec3 p2 = gl_TessCoord.z * tcPosition[2];
    tePosition = (p0 + p1 + p2);
    tePosition.y += fbm(tePosition*2);


    vec4 c0 = gl_TessCoord.x * tcColor[0];
    vec4 c1 = gl_TessCoord.y * tcColor[1];
    vec4 c2 = gl_TessCoord.z * tcColor[2];
    teColor = (c0 + c1 + c2);

    vec2 t0 = gl_TessCoord.x * tcTexCoord[0];
    vec2 t1 = gl_TessCoord.y * tcTexCoord[1];
    vec2 t2 = gl_TessCoord.z * tcTexCoord[2];
    teTexCoord = (t0 + t1 + t2);

    gl_Position = MVP * vec4(tePosition, 1.0);
}
