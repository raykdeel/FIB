// MyGLWidget.h
#include "BL2GLWidget.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);
    virtual void carregaShaders();
    void projectTransform();
    void viewTransform();
    void ini_camera();
    
    GLuint projLoc, viewLoc;
    float FOV, znear, zfar, ra; //ra window
    glm::vec3 OBS, VRP, UP;

};
