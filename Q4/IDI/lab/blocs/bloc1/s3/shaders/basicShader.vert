#version 330 core

in vec3 vertex;
in vec3 col;
out vec4 coli;
uniform mat4 TG;

uniform float val;

void main()  {
    gl_Position = TG * vec4 (vertex*val, 1.0);
    coli=vec4(col,1.0);
}


