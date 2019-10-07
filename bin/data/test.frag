#version 330

uniform vec2 resolution;
uniform float time;

out vec4 outputColor;

void main(){
  outputColor  = vec4(gl_FragCoord.xy/resolution,1.0,1.0);
}
