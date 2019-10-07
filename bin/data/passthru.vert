#version 330

uniform mat4 modelViewProjectionMatrix;


in vec4 position;
in vec2 texcoord;
in vec3 normal;
in vec4 color;

out vec2 vTexcoord;

void main(){
  vTexcoord = texcoord;
  gl_Position = modelViewProjectionMatrix*position;
}
