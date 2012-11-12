#pragma once
#include <painter.h>

class Line : public QGraphicsItem
{
public:
	Line();
	QRect QRectF(const QPointF &topleft, const QPointF &bottomRight);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

