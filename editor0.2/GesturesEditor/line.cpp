#include "line.h"

Line::Line(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) :
	Item(x1, y1, x2, y2)
{

}

QRectF Line::boundingRect() const{
	if (mX1 <= mX2) {
		if (mY1 <= mY2) {
			QPoint topLeft = QPoint(mX1, mY1);
			QPoint bottomRight = QPoint(mX2, mY2);
			return QRectF(topLeft, bottomRight);
		} else {
			QPoint topLeft = QPoint(mX1, mY2);
			QPoint bottomRight = QPoint(mX2, mY1);
			return QRectF(topLeft, bottomRight);
		}
	} else {
		if (mY1 <= mY2) {
			QPoint topLeft = QPoint(mX2, mY1);
			QPoint bottomRight = QPoint(mX1, mY2);
			return QRectF(topLeft, bottomRight);
		} else {
			QPoint topLeft = QPoint(mX2, mY2);
			QPoint bottomRight = QPoint(mX1, mY1);
			return QRectF(topLeft, bottomRight);
		}
	}
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->setPen(this->mPen);
	this->drawItem(painter, option, widget);
	this->drawScalingRects(painter);
}

void Line::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->drawLine(this->mX1, this->mY1, this->mX2, this->mY2);
}

void Line::drawScalingRects(QPainter* painter)
{
	painter->setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
	if (mX2 >= mX1) {
		if (mY2 >= mY1) {
			QRectF leftScalRect = QRectF(QPoint(mX1 - scalingRect, mY1), QPoint(mX1, mY1 - scalingRect));
			QRectF rightScalRect = QRectF(QPoint(mX2, mY2 + scalingRect), QPoint(mX2 + scalingRect, mY2));
			painter->drawPoint(QPoint(mX1 - scalingRect, mY1));
			painter->drawPoint(QPoint(mX2, mY2 + scalingRect));
//			painter->drawRect(leftScalRect);
//			painter->drawRect(rightScalRect);
		} else {
			QRectF leftScalRect = QRectF(QPoint(mX1 - scalingRect, mY1), QPoint(mX1, mY1 + scalingRect));
			QRectF rightScalRect = QRectF(QPoint(mX2, mY2 - scalingRect), QPoint(mX2 + scalingRect, mY2));
//			painter->drawRect(leftScalRect);
//			painter->drawRect(rightScalRect);
		}
	} else {
		if (mY2 <= mY1) {
			QRectF leftScalRect = QRectF(QPoint(mX2 - scalingRect, mY2 - scalingRect), QPoint(mX2, mY2));
			QRectF rightScalRect = QRectF(QPoint(mX1, mY1), QPoint(mX1 + scalingRect, mY1 + scalingRect));
//			painter->drawRect(leftScalRect);
//			painter->drawRect(rightScalRect);
		} else {
			QRectF leftScalRect = QRectF(QPoint(mX2 - scalingRect, mY2), QPoint(mX2, mY2 + scalingRect));
			QRectF rightScalRect = QRectF(QPoint(mX1, mY1 - scalingRect), QPoint(mX1 + scalingRect, mY1));
//			painter->drawRect(leftScalRect);
//			painter->drawRect(rightScalRect);
		}
	}

}

void Line::resizeItem(QGraphicsSceneMouseEvent *event)
{
	if (mDragState == TopLeft || mDragState == BottomRight)
		Item::resizeItem(event);
}

