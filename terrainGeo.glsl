#version 430

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 teColor[];
in vec2 teTexCoord[];
in vec3 tePosition[];
in vec3 teNormal[];

uniform vec3 viewPos;
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 N;

out vec3 fNormal;
out vec4 fColor;
out vec2 fTexCoord;
out vec3 fPosition;
out vec3 tangent, bitangent;
out vec3 TangentLightPos;
out vec3 TangentViewPos;
out vec3 TangentFragPos;

void main( void )
{
    vec3 edge01 = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 edge02 = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;

    vec3 Nv = normalize( cross(normalize(cross(edge01, edge02)), vec3(1,0,0)) );

    for( int i=0; i < gl_in.length( ); i++ )
    {
        fColor = teColor[i];
        fTexCoord = teTexCoord[i];
        fPosition = tePosition[i];
        gl_Position = MVP * gl_in[i].gl_Position;
        fNormal = teNormal[i];

        //normalize(cross(gl_in[i+2].gl_Position.xyz - gl_in[i].gl_Position.xyz, gl_in[i+1].gl_Position.xyz - gl_in[i].gl_Position.xyz));
        EmitVertex( );
    }

//    vec2 deltaUV1 = teTexCoord[1] - teTexCoord[0];
//    vec2 deltaUV2 = teTexCoord[2] - teTexCoord[0];
//
//    float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//    tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//    tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//    tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//    tangent = normalize(tangent);
//
////    bitangent.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
////    bitangent.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
////    bitangent.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
////    bitangent1 = glm::normalize(bitangent1);
//
//    bitangent = cross(fNormal, tangent);
//    vec3 T = normalize(mat3(M) * tangent);
//    vec3 B = normalize(mat3(M) * bitangent);
//    vec3 N1 = normalize(mat3(M) * fNormal);
//    mat3 TBN = transpose(mat3(T, B, N1));
//
//    TangentLightPos = TBN * lightPos;
//    TangentViewPos  = TBN * viewPos;
//    TangentFragPos  = TBN * fragPos;

    EndPrimitive( );
}
