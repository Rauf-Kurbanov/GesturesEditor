#include "line.h"

Line::Line(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : Item(x1, y1, x2, y2) {

}

QRectF Line::boundingRect() const {
	return this->mBoundingRect;
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
}

void Line::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->drawLine(this->mX1, this->mY1, this->mX2, this->mY2);
}


