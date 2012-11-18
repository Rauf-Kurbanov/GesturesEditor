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
	void drawRect(bool checked);
	void drawEllipse(bool checked);
	void drawArc(bool checked);

private:
	QPen mPen;

	enum ItemTypes {
		none
		, line
		, rectangle
		, ellipse
		, arc
	};

	ItemTypes mItemType;

	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

