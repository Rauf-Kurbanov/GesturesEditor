#include "ellipse.h"

Ellipse::Ellipse(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : Item(x1, y1, x2, y2) {

}

QRectF Ellipse::boundingRect() const {
	QPoint topLeft = QPoint(this->mX1, this->mY1);
	QPoint bottomRight = QPoint(this->mX2, this->mY2);
	return QRectF(topLeft, bottomRight);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
	if (this->isSelected()) {
		this->drawScalingRects(painter);
	}
}

void Ellipse::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPoint topLeftPoint = QPoint(this->mX1, this->mY1);
	QPoint bottomRightPoint = QPoint(this->mX2, this->mY2);
	QRectF rectangleForEllipse = QRectF(topLeftPoint, bottomRightPoint);
	painter->drawEllipse(rectangleForEllipse);
}

void Ellipse::drawScalingRects(QPainter *painter) {
	painter->setPen(QPen(Qt::lightGray, 1, Qt::DashLine, Qt::RoundCap));
	painter->drawRect(this->boundingRect());
}

