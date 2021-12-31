// MyGLWidget.h
#include "BL2GLWidget.h"
#include "Model/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);
    virtual void initializeGL();
    virtual void creaBuffers();
    virtual void carregaShaders();
    virtual void paintGL();
    void projectTransform();
    void viewTransform();
    void ini_camera();
    
    GLuint projLoc, viewLoc;
    float FOV, znear, zfar, ra; //ra window
    glm::vec3 OBS, VRP, UP;

    Model m;

    GLuint VAO_model;

};
