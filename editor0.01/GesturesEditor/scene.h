#pragma once
#include <QtGui>
#include "line.h"

class Scene : public QGraphicsScene
{
public:
    Scene();
    void drawLine();
    void drawEllipse();
    void drawRectangle();
    void clearScene();
private:
	QPen *mPen;

};

