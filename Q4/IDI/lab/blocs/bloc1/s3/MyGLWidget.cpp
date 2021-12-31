
//#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  scl = 0.6;
  x = 0., y = 0.;
  rotation = 0.;
  //glm::mat4 aux(1.0); // Matriu de transformació, inicialment identitat
  glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  creaBuffers();
}

void MyGLWidget::paintGL ()
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#endif

// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

  // Activem l'Array a pintar 
  glBindVertexArray(VAO1);
  
  transLoc = glGetUniformLocation(program->programId(), "TG");

  
  varLoc = glGetUniformLocation(program->programId(), "val");
  glUniform1f(varLoc, scl);
  

 
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
  
  // Desactivem el VAO
  glBindVertexArray(0);

  glBindVertexArray(VA02);
 
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::modelTransform () {
    glm::mat4 TG(1.);// Matriu de transformació, inicialment identitat
    TG = glm::translate(glm::mat4(1.0), glm::vec3 (x, y, 0.));
    TG = glm::rotate(TG, rotation, glm::vec3(0.,0.,1.));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}



void MyGLWidget::keyPressEvent(QKeyEvent *e){
    makeCurrent ();
    switch (e->key()) {
        case Qt::Key_Q :
            scl += 0.1;
            glUniform1f(varLoc, scl);
            break;
        case Qt::Key_W :
            scl -= 0.1;
            glUniform1f(varLoc, scl);
            break;
        case Qt::Key_Up :
            y += 0.1;
            rotation += float(M_PI/4);
            modelTransform();
            break;
        case Qt::Key_Down :
            y -= 0.1;
            rotation -= float(M_PI/4);
            modelTransform();
            break;
        case Qt::Key_Right :
            x += 0.1;
            rotation += float(M_PI/4);
            modelTransform();
            break;
        case Qt::Key_Left :
            x -= 0.1;
            rotation -= float(M_PI/4);
            modelTransform();
            break;
        case Qt::Key_P :
            rotation += float(M_PI/6);
            modelTransform();
            break;
        default: e->ignore(); // propagar al pare
    }
    update();
}

void MyGLWidget::resizeGL (int w, int h)
{
  ample = w;
  alt = h;
}

void MyGLWidget::creaBuffers ()
{
  glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0);
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0);
  
  glm::vec3 Color[3];  // Tres vèrtexs amb X, Y i Z
  Color[0] = glm::vec3(1., 0., 0.);
  Color[1] = glm::vec3(0.,1., 0.);
  Color[2] = glm::vec3(0., 0., 1.);
  
  glm::vec3 Vertices2[3];
  Vertices2[0] = glm::vec3(0.5,0.5, 0.0);
  Vertices2[1] = glm::vec3(-0.5, 0.5, 0.0);
  Vertices2[2] = glm::vec3(-0.0, 0.75, 0.0);
  
  
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO1);
  glBindVertexArray(VAO1);

  // Creació del buffer amb les dades dels vèrtexs
  glUniform1f(varLoc, 0.1);
  GLuint VBO1;
  glGenBuffers(1, &VBO1);
  glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  
  vertexLoc = glGetAttribLocation(program->programId(),"vertex");
  
  
  
  
  
  
  
  
  
  
  //S'hauria de fer vertexLoc2 i transLoc2 i després modificar els shaders.
  
  
  
  
  
  
  
  
  

  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  

  glGenBuffers(1, &VBOC);
  glBindBuffer(GL_ARRAY_BUFFER, VBOC);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Color), Color, GL_STATIC_DRAW);
  
  colorLoc = glGetAttribLocation(program->programId(),"col");

  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
  // Desactivem el VAO
  
  glBindVertexArray(0);
  //glBindVertexArray(colorLoc);
  //glBindVertexArray(vertexLoc);
  
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1,&VA02);
  glBindVertexArray(VA02);
  
  // Creació del buffer amb les dades dels vèrtexs
  glGenBuffers(1,&VB02);
  glBindBuffer(GL_ARRAY_BUFFER,VB02);
  glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices2),Vertices2,GL_STATIC_DRAW);
  
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
  glEnableVertexAttribArray(0);
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/basicShader.frag");
  vs.compileSourceFile("shaders/basicShader.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
}



