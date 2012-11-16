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
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	virtual void reshapeLine(QGraphicsSceneMouseEvent *event);
	QGraphicsLineItem *mLine;
	QPen mPen;
};

