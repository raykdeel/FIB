#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  
  glEnable(GL_DEPTH_TEST);
  
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  creaBuffersEscac();
  creaBuffersHomer();
  OBSx = 0.5;
  OBSy = 2;
  OBSz = 15;
  iniEscena();
  iniCamera();
}

void MyGLWidget::paintGL () {
    // descomentar per canviar paràmetres
    // glViewport (0, 0, ample, alt);
    // Esborrem el frame-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Homer
    homerTransform(xH, zH);
    glBindVertexArray (VAO_Homer);
    glUniform1i(indexColorLoc, 2);  // color = 2 -- color per vèrtex
    glDrawArrays(GL_TRIANGLES, 0, homer.faces().size()*3);
    glBindVertexArray (0);

    // Escac
    glBindVertexArray (VAO_Escac);
    int xe, ze;
    xe = -3;
    ze = -3;
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            escacTransform(xe, ze);
            glUniform1i(indexColorLoc, (i+j)%2);  // color = 1 -- color escac blanc (0.8, 0.8, 0.8)
            glDrawArrays(GL_TRIANGLES, 0, 6);
            ++xe;
        }
        xe = -3;
        ++ze;
    }
    glBindVertexArray (0);
}

void MyGLWidget::projectTransform ()
{
  glm::mat4 Proj(1.0f);
  if(!top) Proj = glm::perspective (fov, ra, znear, zfar);
  else Proj = glm::perspective(fov, ra, znear, zfar);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}


void MyGLWidget::viewTransform ()
{
  // Matriu de posició i orientació de l'observador
  glm::mat4 View(1.0f);
  View = glm::lookAt (obs, vrp, up);
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::iniCamera(){
    OBSx = 0.5;
    OBSy = 2;
    OBSz = 15;
    obs = glm::vec3(OBSx, OBSy, OBSz);
    vrp = glm::vec3(0.5, 0, 0.5);
    up = glm::vec3(0, 1, 0);
    fov = float(M_PI)/4.0f;
    ra  = 1.0;
    znear = 1; //6.5
    zfar  = 19;
    top = false;

    viewTransform();
    projectTransform();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
    makeCurrent();
    switch (event->key()) {
        case Qt::Key_1 :
            if(validPos(xH+deltai[0],zH+deltaj[0])) {
                xH +=deltai[0];
                zH +=deltaj[0];
                if(!orientation()) angleH = float(M_PI);
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_2 :
            if(validPos(xH+deltai[1],zH+deltaj[1])) {
                xH +=deltai[1];
                zH +=deltaj[1];
                if(!orientation()) angleH = -float(M_PI)/2;
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_3 :
            if(validPos(xH+deltai[2],zH+deltaj[2])) {
                xH +=deltai[2];
                zH +=deltaj[2];
                if(!orientation()) angleH = -float(M_PI)/2;
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_4 :
            if(validPos(xH+deltai[3],zH+deltaj[3])) {
                xH +=deltai[3];
                zH +=deltaj[3];
                if(!orientation()) angleH = 0;
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_5 :
            if(validPos(xH+deltai[4],zH+deltaj[4])) {
                xH +=deltai[4];
                zH +=deltaj[4];
                if(!orientation()) angleH = 0;
                homerTransform(xH,zH);
            }
            break;

        case Qt::Key_6 :
            if(validPos(xH+deltai[5],zH+deltaj[5])) {
                xH +=deltai[5];
                zH +=deltaj[5];
                if(!orientation()) angleH = float(M_PI)/2;
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_7 :
            if(validPos(xH+deltai[6],zH+deltaj[6])) {
                xH +=deltai[6];
                zH +=deltaj[6];
                if(!orientation()) angleH = float(M_PI)/2;
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_8 :
            if(validPos(xH+deltai[7],zH+deltaj[7])) {
                xH +=deltai[7];
                zH +=deltaj[7];
                if(!orientation()) angleH = float(M_PI);
                homerTransform(xH,zH);
            }
            break;
        case Qt::Key_C :
            top = !top;
            if(top) {
                OBSx = 0.5;
                OBSy = 6;
                OBSz = 0.51;
                fov = float(M_PI)/2.0f;
                obs = glm::vec3(OBSx,OBSy,OBSz);
            } else iniCamera();
            viewTransform();
            projectTransform();
            break;
        case Qt::Key_R :
            angleH = .0;
            xH = zH = 0;
            if(top) {
                top = false;
                iniCamera();
                viewTransform();
                projectTransform();
                projectTransform();
            }
            homerTransform(xH,zH);
            break;
        default: event->ignore(); break;
    }
    update();
}

bool MyGLWidget::validPos(int x, int z) {
    return(x >= -3 and x <= 4 and z >= -3 and z <= 4);
}

bool MyGLWidget::orientation() {
    if(xH == -3) angleH = float(M_PI)/2;
    else if(xH == 4) angleH = -float(M_PI)/2;
    else {
        if(zH == -3) angleH = 0;
        else if(zH == 4) angleH = float(M_PI);
    }
    if(xH == -3 or xH == 4 or zH == -3 or zH == 4) return true;
    return false;
}


