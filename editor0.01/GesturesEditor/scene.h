#ifndef SCENE_H
#define SCENE_H
#include <QtGui>

class Scene : public QGraphicsScene
{
public:
    Scene();
    void drawLine();
    void drawEllipse();
    void drawRectangle();
    void clearScene();
private:

};

#endif // SCENE_H
