#version 430 core

in vec3 vcNormal;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;

uniform sampler2D terra;
uniform sampler2D agua;
uniform sampler2D grama;
uniform sampler2D snow;
uniform sampler2D mountain;

out vec4 fragColor;

#define clamp01(x) clamp(x, 0.0, 1.0)

vec4 texAgua = texture2D(agua, vcTexCoord);
vec4 texTerra = texture2D(terra, vcTexCoord);
vec4 texGrama = texture2D(grama, vcTexCoord);
vec4 texSnow = texture2D(snow, vcTexCoord);
vec4 texMountain = texture2D(mountain, vcTexCoord);

float weightWater;
float weightStone;
float weightGrass;

vec3 heightblend(vec3 tex1, float height1, vec3 tex2, float height2)
{
    float heightBlendFactor = 1.f;
    float height_start = max(height1, height2 - 1) - heightBlendFactor;
    float level1 = max(height1 - height_start, 0);
    float level2 = max(height2 - height_start -1, 0);
    return ((tex1 * level1) + (tex2 * level2)) / (level1 + level2);
}

vec3 surf(vec4 tex1, float h1, vec4 tex2, float h2)
{
    vec3 t1 = tex1.rgb;
    vec3 t2 = tex2.rgb;
    return heightblend (t1, h1, t2, h2);
}

void main(){
    float height = p;
    vec4 blank = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
    vec4 blue = vec4 ( 0.0f, 0.0f, 1.0f, 1.0f );
    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );

    const float leveli1 = -2.f;
    const float level0 = 0.f;
	const float level1 = 2.f;
	const float level2 = 4.f;
	const float level3 = 6.f;
	const float level4 = 8.f;

	if(height <= leveli1){
        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
	}
	else if(height > leveli1 && height <= level0){
        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
	}
	else if(height > level0 && height <= level2){
        vTexColor = vec4(surf(texGrama, level0, texTerra , height), 1.f);
    }
    else if(height > level2 && height <= level3){
        vTexColor = vec4(surf(texTerra, level2, texMountain, height), 1.f);
    }
    else if(height > level3){
        vTexColor = vec4(surf(texMountain , level3 , texSnow , height-1), 1.f);
    }

	vec4 vFinalTexColor = vTexColor;

   	fragColor = vFinalTexColor;
}