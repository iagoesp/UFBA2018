#version 430 core

in vec3 vNormal;
in vec4 vColor;
in vec2 vTexCoord;
in float h;

out vec4 fragColor;

void main(){

  fragColor = vec4(0, h, h, 1.f);
}
//
//void main() {
//  vec3 normal = normalize(vcNormal);
//  vec3 light1 = normalize( vec3(30.f, 15.f, 30.f) );
//
//  vec3 ref = reflect( tePosition, normal );
//  float fre = clamp( 1.0+dot(tePosition,normal), 0.0, 1.0 );
//  vec3 hal = normalize(light1-tePosition);
//
//
//  float sundot = clamp(dot(tePosition,light1),0.0,1.0);
//  //rock
//  float count = 15;
//  float r = noise(tePosition.xz*count);
//
//  vec3 col = (r*0.25+0.75)*0.9*mix( vec3(0.08,0.05,0.03), vec3(0.10,0.09,0.08), clamp(terrain2( vec2(tePosition.x,tePosition.y*48.0))/200.0,0.0,1.0));
//  col = mix( col, 0.20*vec3(0.45,.30,0.15)*(0.50+0.50*r),smoothstep(0.70,0.9,normal.y) );
//  col = mix( col, 0.15*vec3(0.30,.30,0.10)*(0.25+0.75*r),smoothstep(0.95,1.0,normal.y) );
//  col *=0.9;
//
//  // snow
//  float h = smoothstep(55.0,80.0, tePosition.y + 25.0*terrain2(0.01*tePosition.xz) );
//  float e = smoothstep(1.0-0.5*h,1.0-0.1*h,normal.y);
//  float o = 0.3 + 0.7*smoothstep(0.0,0.1,normal.x+h*h);
//  float s = h*e*o;
//  col = mix( col, 0.29*vec3(0.62,0.65,0.7), smoothstep( 0.1, 0.9, s ) );
//
//  // lighting
//  float amb = clamp(0.5+0.5*normal.y,0.0,1.0);
//  float dif = clamp( dot( light1, normal ), 0.0, 1.0 );
//  float bac = clamp( 0.2 + 0.8*dot( normalize( vec3(-light1.x, 0.0, light1.z ) ), normal ), 0.0, 1.0 );
//  float sh = 1.0;
//  if( dif>=0.0001 )
//    sh = softShadow(tePosition+light1*0.05, light1);
//
//  vec3 lin  = vec3(0.0);
//  lin += dif*vec3(7.00,5.00,3.00)*1.3*vec3( sh, sh*sh*0.5+0.5*sh, sh*sh*0.8+0.2*sh );
//  lin += amb*vec3(0.40,0.60,1.00)*1.2;
//  lin += bac*vec3(0.40,0.50,0.60);
//  col *= lin;
//
//  col += s*0.1*pow(fre,4.0)*vec3(7.0,5.0,3.0)*sh * pow( clamp(dot(light1,ref), 0.0, 1.0),16.0);
//  col += s*0.1*pow(fre,4.0)*vec3(0.4,0.5,0.6)*smoothstep(0.0,0.6,ref.y);
//
//  //col = pow(col,vec3(0.45));
//	col += 0.3*vec3(1.0,0.8,0.4)*pow( sundot, 8.0 )*(1.0-exp(-0.002*t));
//
//
//  //col = col*0.6 + 0.4*col*col*(3.0-2.0*col);
//  col *= 0.7;
////
////  float dist = length(light1 - tvPosition);
////  vec3 L = normalize( light1 - tvPosition);
////  vec3 V = normalize( viewPos - tePosition);
////  float difuza = max(0.1, dot(L, normal));
////
////  //difuza = difuza * (1.0 / (1.0 + (0.25 * dist * dist)));
////
////  vec3 Kd = vec3(0.50,0.50,0.50);
////  Kd = Kd * 0.5 * difuza ;
////  col = col + Kd ;
//
//  //col = sqrt(col);
//  fragColor = vec4(col, 1.f);
//}

//void main(){
//    float height = p;
//    vec4 blank = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
//    vec4 blue = vec4 ( 0.0f, 0.0f, 1.0f, 1.0f );
//    vec4 vTexColor = vec4 ( 1.0f, 1.0f, 1.0f, 1.0f );
//
//    const float leveli1 = -2.f;
//    const float level0 = 0.f;
//	const float level1 = 2.f;
//	const float level2 = 4.f;
//	const float level3 = 6.f;
//	const float level4 = 8.f;
//
//	if(height <= leveli1){
//        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
//	}
//	else if(height > leveli1 && height <= level0){
//        vTexColor = vec4(surf(texAgua, leveli1, texGrama , height), 1.f);
//	}
//	else if(height > level0 && height <= level2){
//        vTexColor = vec4(surf(texGrama, level0, texTerra , height), 1.f);
//    }
//    else if(height > level2 && height <= level3){
//        vTexColor = vec4(surf(texTerra, level2, texMountain, height), 1.f);
//    }
//    else if(height > level3){
//        vTexColor = vec4(surf(texMountain , level3 , texSnow , height-1), 1.f);
//    }
//
//    vec4 vFinalTexColor;
//        //vFinalTexColor= vcColor;
//        vFinalTexColor = vTexColor;
//
//   	fragColor = vFinalTexColor;
//}

