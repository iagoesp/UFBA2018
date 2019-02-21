#version 430 core

in vec3 vcNormal;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;

uniform sampler2D terra;
uniform sampler2D agua;
uniform sampler2D grama;
uniform sampler2D snow;

out vec4 fragColor;

#define clamp01(x) clamp(x, 0.0, 1.0)

vec4 texAgua = texture2D(agua, vcTexCoord);
vec4 texTerra = texture2D(terra, vcTexCoord);
vec4 texGrama = texture2D(grama, vcTexCoord);
vec4 texSnow = texture2D(snow, vcTexCoord);

float weightWater;
float weightStone;
float weightGrass;
float heightBlendFactor = 1.f;



vec3 heightblend(vec3 tex1, float height1, vec3 tex2, float height2)
{
    float height_start = max(height1, height2) - heightBlendFactor;
    float level1 = max(height1 - height_start, 0);
    float level2 = max(height2 - height_start, 0);
    return ((tex1 * level1) + (tex2 * level2)) / (level1 + level2);
}

vec3 surf(vec4 tex1, float h1, vec4 tex2, float h2)
{
    vec3 t1 = tex1.rgb;
    vec3 t2 = tex2.rgb;
    return heightblend (t1, h1, t2, h2);
}

vec3 blend(vec4 texture1, float a1, vec4 texture2, float a2)
{
    float depth = 0.2;
    float ma = max(texture1.a + a1, texture2.a + a2) - depth;

    float b1 = max(texture1.a + a1 - ma, 0);
    float b2 = max(texture2.a + a2 - ma, 0);

    return (texture1.rgb * b1 + texture2.rgb * b2) / (b1 + b2);
}

void main(){
    float height = p;
    vec4 blank = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );

    const float level0 = 0.f;
	const float level1 = 1.f;
	const float level2 = 3.0f;
	const float level3 = 4.f;

	if(height <= level0){
        vTexColor = vec4(surf(texGrama , height, texTerra, level0), 1.f);
	}
	else if(height > level0 && height <= level1){
        vTexColor = vec4(surf(texTerra, level0, texGrama, height), 1.f);
    }
    else if(height > level1){
        vTexColor = vec4(surf(texGrama , level1 , texSnow, height-1), 1.f);
    }

	vec4 vFinalTexColor = vTexColor;

   	fragColor = vFinalTexColor;
}
