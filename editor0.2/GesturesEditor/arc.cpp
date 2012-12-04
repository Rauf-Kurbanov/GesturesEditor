#include "arc.h"

Arc::Arc(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent)
	: Item(x1, y1, x2, y2) {
	mCX = x3;
	mCY = y3;
}

QRectF Arc::boundingRect() const {
	if (mCX >= qMax(mX1, mX2)) {
		qreal maxLineY = qMax(mY1, mY2);
		qreal minLineY = qMin(mY1, mY2);
		QPoint topLeft = QPoint(qMin(mX1, mX2), qMin(minLineY, mCY));
		QPoint bottomRight = QPoint(mCX, qMax(maxLineY, mCY));
		return QRectF(topLeft, bottomRight);
	} else {
		if (mCX <= qMin(mX1, mX2)) {
			QPoint topLeft = QPoint(mCX, qMin(qMin(mY1, mY2), mCY));
			QPoint bottomRight = QPoint(qMax(mX1, mX2), qMax(qMax(mY1, mY2), mCY));
			return QRectF(topLeft, bottomRight);
		} else {
			if (mCY <= qMax(mY1, mY2)) {
				QPoint topLeft = QPoint(qMin(mX1, mX2), qMin(mCY, qMin(mY1, mY2)));
				QPoint bottomRight = QPoint(qMax(mX1, mX2), qMax(mY1, mY2));
				return QRectF(topLeft, bottomRight);
			} else {
				QPoint topLeft = QPoint(qMin(mX1, mX2), qMin(mCY, qMin(mY1, mY2)));
				QPoint bottomRight = QPoint(qMax(mX1, mX2), mCY);
				return QRectF(topLeft, bottomRight);
			}
		}
	}
	return QRectF(QPoint(0, 0), QPoint(0, 0));
}

void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
	if (this->isSelected()) {
		this->drawScalingRects(painter);
	}
}

void Arc::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	this->mPath = new QPainterPath(QPointF(this->mX1, this->mY1));
	QPoint centerPoint = QPoint(mCX, mCY);
	this->mPath->quadTo(centerPoint, QPointF(this->mX2, this->mY2));
	painter->drawPath(*mPath);
}

void Arc::setCXandCY(qreal x, qreal y)
{
	mCX = x;
	mCY = y;
	this->mPath = new QPainterPath(QPointF(this->mX1, this->mY1));
}

void Arc::drawScalingRects(QPainter *painter) {
	painter->setPen(QPen(Qt::lightGray, 1, Qt::DashLine, Qt::RoundCap));
	painter->drawRect(this->boundingRect());
}
