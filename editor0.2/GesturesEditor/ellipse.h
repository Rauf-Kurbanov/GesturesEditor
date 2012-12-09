#pragma once

#include <QtGui>
#include "item.h"

class Ellipse : public Item
{
public:
	Ellipse(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawScalingRects(QPainter* painter);
	virtual void changeDragState(qreal x, qreal y);
	virtual void updateScalingRects(QPointF topLeft, QPointF bottomRight);
	virtual QRectF boundingRect() const;

private:
	QRectF leftBottomScalRect;
	QRectF leftTopScalRect;
	QRectF rightTopScalRect;
	QRectF rightBottomScalRect;
};

