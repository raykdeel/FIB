#version 330 core

in vec3 fcolor;

uniform int canviColor;

out vec4 fragColor;

vec3 roig = vec3(1.0, 0.0, 0.0);
vec3 verd = vec3(0., 1., 0.);
vec3 blau = vec3(0., 0., 1.);

void main() {
    if (canviColor == 1) fragColor = vec4(roig, 1);
    else if (canviColor == 2) fragColor = vec4(verd, 1);
    else if (canviColor == 3) fragColor = vec4(blau, 1);
    else fragColor = vec4(fcolor, 1);
}

