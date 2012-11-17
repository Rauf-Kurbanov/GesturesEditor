#pragma once

#include <QtGui>
#include "item.h"

class Line : public Item
{
public:
	Line(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);
//	void setX2andY2(qreal x, qreal y);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	virtual QRectF boundingRect() const;

	QRectF mBoundingRect;
	QPen mPen;
	QBrush mBrush;
	qreal mX1;
	qreal mY1;
	qreal mX2;
	qreal mY2;
};


