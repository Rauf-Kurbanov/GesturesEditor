#pragma once

#include <QtGui>
#include "item.h"

class Arc : public Item
{
public:
	Arc(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);
	qreal mX1;
	qreal mY1;
	qreal mX2;
	qreal mY2;
};

