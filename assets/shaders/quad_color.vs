#version 330 core

layout (location = 0) in vec3 a_pos;

uniform mat4 u_model;
uniform mat4 u_projectionView;
uniform vec4 u_color;

out vec4 v_color;

void main()
{
    gl_Position = u_projectionView * u_model * vec4(a_pos, 1.0);
    v_color = u_color;
}