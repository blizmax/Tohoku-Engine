// debug/texture2D.frag

#version 330 core

precision highp float;
precision mediump int;

uniform sampler2D texunit;

smooth in vec2 texcoords;

out vec4 frag_color;

void main()
{
	frag_color = texture(texunit, texcoords);
}
