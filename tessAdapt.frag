#version 430 core

in vec3 vcNormal;
in vec4 vcColor;
in float p;
in vec2 vcTexCoord;


uniform sampler2D texture1;

out vec4 fragColor;

void main(){

    //fragColor = vcColor;
    fragColor = texture(texture1, vcTexCoord);
}
