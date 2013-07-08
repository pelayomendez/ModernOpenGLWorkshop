#version 120
#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect tex;
uniform float time;
varying vec2 textCoord0;

/*
** Desaturation
*/

vec4 Desaturate(vec3 color, float Desaturation)
{
	vec3 grayXfer = vec3(0.3, 0.59, 0.11);
	vec3 gray = vec3(dot(grayXfer, color));
	return vec4(mix(color, gray, Desaturation), 1.0);
}

/*
** Invert
*/

vec4 Invert(vec4 color)
{
	return 1.-color;
}

/*
** Blur
*/

vec4 Blur(vec3 color)
{

	//vec3 color = vec3(0.3, 0.59, 0.11);
    for(int y =-2;y<3;y++) {
    	for(int x =-2;x<3;x++) {
    		color += texture2DRect(tex,textCoord0+vec2(x,y)).rgb;
    	}
	}
	color /= 25.;
	return vec4(color,1.);

}

void main(){

	vec4 color = texture2DRect(tex,textCoord0);
	//gl_FragColor = 1.-color;
	gl_FragColor = Blur(color.rgb);
	//gl_FragColor = Invert(color);
	
}