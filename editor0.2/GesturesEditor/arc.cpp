#include "arc.h"

Arc::Arc(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent)
	: Item(x1, y1, x2, y2) {

	this->mCPoint = QPoint(x3, y3);
}

QRectF Arc::boundingRect() const {
	QPoint topLeft = QPoint(this->mX1, this->mY1);
	QPoint bottomRight = QPoint(this->mX2, this->mY2);
	return QRectF(topLeft, bottomRight);
}

void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
}

void Arc::setCXandCY(qreal x, qreal y)
{
	this->mCPoint = QPoint(x, y);
	this->mPath = new QPainterPath(QPointF(this->mX1, this->mY1));
}

void Arc::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	this->mPath = new QPainterPath(QPointF(this->mX1, this->mY1));
	this->mPath->quadTo(this->mCPoint, QPointF(this->mX2, this->mY2));
	painter->drawPath(*mPath);
}

