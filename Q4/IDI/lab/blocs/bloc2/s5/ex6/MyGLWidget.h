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
    virtual void modelTransform_model();
    void modelTransform_ground();
    virtual void carregaShaders();
    virtual void resizeGL(int w,int h);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void paintGL();
    void projectTransform();
    void viewTransform();
    void ini_camera();
    void calculaCapsaModel ();
    void calculaCapsaEscena ();
    void calculCentreEscnea ();
    void calculRadiEscena ();
    
    GLuint projLoc, viewLoc;
    float FOV, FOVini, znear, zfar, ra, rav; //ra window
    glm::vec3 OBS, VRP, UP;

    Model m;

    GLuint VAO_model, VAO_ground;
    
    float rotate, Xground, Zground, OBSy, OBSx;

    glm::vec3 escenaMinima, escenaMaxima, centreEscena, centreBasePatricio;

    float radi, dist;

    bool perspective;

};
