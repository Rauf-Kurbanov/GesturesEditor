#pragma once

#include <QtGui>
#include "item.h"

class Line : public Item
{
public:
	Line(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawScalingRects(QPainter *painter);
	virtual QRectF boundingRect() const;
};


