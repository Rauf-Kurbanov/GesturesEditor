#pragma once

#include <QtGui>
#include "item.h"

class Arc : public Item
{
public:
	Arc(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent = 0);

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void drawScalingRects(QPainter *painter);
	virtual QRectF boundingRect() const;

	void  setCXandCY(qreal x, qreal y);

private:
	QPainterPath *mPath;
	qreal mCX;
	qreal mCY;
};

