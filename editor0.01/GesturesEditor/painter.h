#pragma once
#include <QtGui>

class Painter : public QPainter
{
public:
	Painter(QGraphicsView *view);
};


