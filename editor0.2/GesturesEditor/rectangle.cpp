#include "rectangle.h"

Rectangle::Rectangle(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : Item(x1, y1, x2, y2) {

}

QRectF Rectangle::boundingRect() const {
	return this->mBoundingRect;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
}

void Rectangle::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPoint topLeftPoint = QPoint(this->mX1, this->mY1);
	QPoint bottomRightPoint = QPoint(this->mX2, this->mY2);
	QRectF rectangle = QRectF(topLeftPoint, bottomRightPoint);
	painter->drawRect(rectangle);
}
