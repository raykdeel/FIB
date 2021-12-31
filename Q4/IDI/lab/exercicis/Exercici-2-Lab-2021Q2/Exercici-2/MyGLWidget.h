#define GLM_FORCE_RADIANS
#include "LL2GLWidget.h"

#include "model.h"

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void paintGL();
    virtual void iniCamera();
    virtual void projectTransform();
    virtual void viewTransform();
    virtual void initializeGL();
    bool validPos(int x,int y);
    bool orientation();
    

    bool top;
    float OBSx, OBSy, OBSz;





};
