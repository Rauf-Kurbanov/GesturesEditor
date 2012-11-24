#include "arc.h"

Arc::Arc(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : Item(x1, y1, x2, y2) {

}

QRectF Arc::boundingRect() const {
	return this->mBoundingRect;
}

void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
}

void Arc::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPoint topLeftPoint = QPoint(this->mX1, this->mY1);
	QPoint bottomRightPoint = QPoint(this->mX2, this->mY2);
	QRectF rectangleForArc = QRectF(topLeftPoint, bottomRightPoint);
	int startAngle = 30 * 16;
	int spanAngle = 120 * 16;
	painter->drawArc(rectangleForArc, startAngle, spanAngle);
}
