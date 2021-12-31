#version 330 core

out vec4 FragColor;
in vec4 coli;

void main() {

  if((int(gl_FragCoord.y) % 25) <= 20)FragColor=coli;else FragColor= vec4(0.5, 0.7, 1.0, 1.0);

/*
  FragColor=vec4(1.);

  if((int(gl_FragCoord.y) % 28) <= 14){
    if(gl_FragCoord.y<355 && gl_FragCoord.x<355)
      FragColor= vec4(1.,1.,0.,1.);
    else if(gl_FragCoord.y<355 && gl_FragCoord.x>=355)
      FragColor= vec4(0.,1.,0.,1.);
    else if(gl_FragCoord.y>=355 && gl_FragCoord.x>=355)
      FragColor= vec4(0.,0.,1.,0.);
    else if(gl_FragCoord.y>=355 && gl_FragCoord.x<355)
      FragColor= vec4(1.,0.,0.,1.);
    //}
    //else FragColor= vec4(0.5, 0.7, 1.0, 1.0);
    */
}
