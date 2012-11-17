#pragma once

#include <QGraphicsScene>
#include "line.h"
#include "arc.h"
#include "rectangle.h"
#include "ellipse.h"

class Scene : public QGraphicsScene
{
public:
	Scene();
	void drawLine(bool checked);

private:
	QPen mPen;

	enum ItemTypes {
		none
		, line
		, rectangle
		, arc
		, ellipse
	};

	ItemTypes mItemType;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent *event);
	virtual void reshapeLine(QGraphicsSceneMouseEvent *event);

	Line *mLine;
};

