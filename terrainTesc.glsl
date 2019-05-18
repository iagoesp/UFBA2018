#version 430 core

layout(vertices = 3) out;

in vec3 vPosition[];
in vec3 vNormal[];
in vec4 vColor[];
in vec2 TexCoord[];

in vec3 samePosition[];
in float h[];
out float cNoise[];
out vec3 Position[];

out vec3 tcPosition[];
out vec3 tcNormal[];
out vec4 tcColor[];
out vec2 tcTexCoord[];

uniform vec3 viewPos;

uniform int tess;

uniform float dx;
uniform float dy;
uniform mat4 V;
uniform float dz;
uniform float radius;

#define ID gl_InvocationID

float LOD(vec3 posV, vec3 cam){
  float dist = distance(posV, cam);
  if(dist<=50) return 32.0;
  else if(dist>50 && dist<=100) return 16.0;
  else if(dist>100 && dist<=200) return 8.0;
  else if(dist>200 && dist<=300) return 4.0;
  else if(dist>300 && dist<=400) return 2.0;
  else if(dist>400) return 1.0;
}

float dirLOD(vec3 posV, float posCX, float posCY, float posCZ){
  float param = radius*100/4;
  vec3 direction = vec3(posCX, posCY, posCZ);
  float normal = dot(direction, posV);
  if(normal > param) return 8.0;
  else if(normal >= -param && normal <= param) return 4.0;
  else if(normal < -param) return 1.0;
}

vec3 triIntersect( vec3 ro, vec3 rd, vec3 v0, vec3 v1, vec3 v2 )
{
    vec3 v1v0 = v1 - v0;
    vec3 v2v0 = v2 - v0;
    vec3 rov0 = ro - v0;

    vec3  n = cross( v1v0, v2v0 );
    vec3  q = cross( rov0, rd );
    float d = 1.0/dot( rd, n );
    float u = d*dot( -q, v2v0 );
    float v = d*dot(  q, v1v0 );
    float t = d*dot( -n, rov0 );

    if( u < 0.0 || u > 1.0 || v < 0.0 || (u+v) > 1.0 ) t = -1.0;

    return vec3( t, u, v );
}

void main(){
  float TessLevelInner = 1;
  float e0, e1, e2;
  vec3 d1, d2, d3;

  e0 = e1 = e2 = 1;
   tcTexCoord[ID]  = TexCoord[ID];
  tcPosition[ID]  = vPosition[ID];
  Position[ID]  = samePosition[ID];
  tcNormal[ID]    = vNormal[ID];
  tcColor[ID]     = vColor[ID];
  cNoise[ID] = h[ID];


  if (ID == 0) {
    vec3 v0 = gl_in[0].gl_Position.xyz;
    vec3 v1 = gl_in[1].gl_Position.xyz;
    vec3 v2 = gl_in[2].gl_Position.xyz;
    vec3 bTriangulo = (v0 + v1 + v2)/3;

    if(tess==1){
      TessLevelInner = LOD(bTriangulo, viewPos);

      d1=v1+(v2-v1)/2;
      d2=v0+(v2-v0)/2;
      d3=v0+(v1-v0)/2;

      e0=LOD(d1,viewPos);
      e1=LOD(d2,viewPos);
      e2=LOD(d3,viewPos);
    }
    else if(tess == 0){
      TessLevelInner = 1;
    }
    else if(tess == 2){
      TessLevelInner = 2;
    }

    gl_TessLevelInner[0] = TessLevelInner;
    gl_TessLevelOuter[0] = e0;
    gl_TessLevelOuter[1] = e1;
    gl_TessLevelOuter[2] = e2;
  }
  //if(TessLevelInner == 8.0 /*|| TessLevelOuter == 8.0*/){
    //tcColor[ID] == vec4(1.0, 1.0, 1.0, 1.0);
  //}

}

