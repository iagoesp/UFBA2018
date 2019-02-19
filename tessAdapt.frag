#version 430 core

in vec3 vcNormal;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;

uniform sampler2D DecalTex;
uniform sampler2D BumpTex;

out vec4 fragColor;

#define clamp01(x) clamp(x, 0.0, 1.0)

vec3 lerp(vec3 v1, vec3 v2, float t)
{
    t = clamp01(t);
    return v1 + ((v2 - v1) * t);
}

vec3 surf ()
{
    vec3 v1 = texture2D(DecalTex, vcTexCoord).rgb;
    vec3 v2 = texture2D(BumpTex, vcTexCoord).rgb;
    float t = vcTexCoord.x;

    return lerp(v1, v2, t);
}

void main(){
    float height = p;
    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
    vec4 t1 = texture2D(BumpTex, vcTexCoord);
    vec4 t2 = texture2D(DecalTex, vcTexCoord);

    const float fRange1 = -2.5;
	const float fRange2 = 0f;
	const float fRange3 = 2.5f;
	const float fRange4 = 5f;

	if(height <= fRange2)
        vTexColor = t1;
	else if(height > fRange2 && height <= fRange3)
		vTexColor = vec4(surf(), 1.0f);
    else if(height > fRange3 && height <= fRange4)
		vTexColor = t2;
	vec4 vFinalTexColor = vTexColor;

   	fragColor = vFinalTexColor;
}
