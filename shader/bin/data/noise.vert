#version 120

varying vec2 textCoord0;

void main(){

	textCoord0 = gl_MultiTexCoord0.xy;
	
	//get our current vertex position so we can modify it
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;	
	//finally set the pos to be that actual position rendered
	gl_Position = pos;

	gl_FrontColor =  gl_Color;	
}
