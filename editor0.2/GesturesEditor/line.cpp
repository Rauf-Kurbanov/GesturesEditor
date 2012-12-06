#include "line.h"

Line::Line(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) :
	Item(x1, y1, x2, y2)
{
	QPoint firstPoint = QPoint(x1, y1);
	QPoint secondPoint = QPoint(x2, y2);
	updateScalingRects(firstPoint, secondPoint);

}

QRectF Line::boundingRect() const {
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
	if (this->isSelected()) {
		this->drawScalingRects(painter);
	}
}

void Line::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->drawLine(this->mX1, this->mY1, this->mX2, this->mY2);
}

void Line::drawScalingRects(QPainter* painter)
{
	painter->setPen(QPen(Qt::lightGray, 1, Qt::DashLine, Qt::RoundCap));
	painter->drawRect(this->boundingRect());
	painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
	painter->setBrush(this->mBrush);
	QRectF leftScalRect;
	QRectF rightScalRect;
	if (mX2 >= mX1) {
		if (mY2 >= mY1) {
			leftScalRect = QRectF(QPoint(mX1, mY1), QPoint(mX1 + scalingRect, mY1 + scalingRect));
			rightScalRect = QRectF(QPoint(mX2 - scalingRect, mY2 - scalingRect), QPoint(mX2, mY2));
		} else {
			leftScalRect = QRectF(QPoint(mX1, mY1 - scalingRect), QPoint(mX1 + scalingRect, mY1));
			rightScalRect = QRectF(QPoint(mX2 - scalingRect, mY2), QPoint(mX2 , mY2 + scalingRect));
		}
	} else {
		if (mY2 <= mY1) {
			leftScalRect = QRectF(QPoint(mX2, mY2), QPoint(mX2 + scalingRect, mY2 + scalingRect));
			rightScalRect = QRectF(QPoint(mX1 - scalingRect, mY1 - scalingRect), QPoint(mX1, mY1));
		} else {
			leftScalRect = QRectF(QPoint(mX2, mY2 - scalingRect), QPoint(mX2 + scalingRect, mY2));
			rightScalRect = QRectF(QPoint(mX1 - scalingRect, mY1), QPoint(mX1, mY1 + scalingRect));
		}
	}
	painter->drawRect(leftScalRect);
	painter->drawRect(rightScalRect);

}

void Line::changeDragState(qreal x, qreal y) {
	QPoint clickPoint = QPoint(x, y);
	if (leftScalRect.contains(clickPoint)) {
		this->mDragState = TopLeft;
		qDebug() << "mDragState = TopLeft";
	} else {
		if (rightScalRect.contains(clickPoint)) {
			this->mDragState = BottomRight;
			qDebug() << "mDragState = BottomRight";
		} else {
			this->mDragState = None;
			qDebug() << "mDragState = None";
		}
	}
}

void Line::resizeItem(QGraphicsSceneMouseEvent *event)
{
	if (mDragState == TopLeft || mDragState == BottomRight)
		Item::resizeItem(event);
}

void Line::updateScalingRects(QPointF topLeft, QPointF bottomRight) {
	qreal X1 = topLeft.x();
	qreal Y1 = topLeft.y();
	qreal X2 = bottomRight.x();
	qreal Y2 = bottomRight.y();
	if (X2 >= X1) {
		if (Y2 >= Y1) {
			leftScalRect = QRectF(QPoint(X1, Y1), QPoint(X1 + scalingRect, Y1 + scalingRect));
			rightScalRect = QRectF(QPoint(X2 - scalingRect, Y2 - scalingRect), QPoint(X2, Y2));
		} else {
			leftScalRect = QRectF(QPoint(X1, Y1 - scalingRect), QPoint(X1 + scalingRect, Y1));
			rightScalRect = QRectF(QPoint(X2 - scalingRect, Y2), QPoint(X2 , Y2 + scalingRect));
		}
	} else {
		if (mY2 <= mY1) {
			leftScalRect = QRectF(QPoint(X2, Y2), QPoint(X2 + scalingRect, Y2 + scalingRect));
			rightScalRect = QRectF(QPoint(X1 - scalingRect, Y1 - scalingRect), QPoint(X1, Y1));
		} else {
			leftScalRect = QRectF(QPoint(X2, Y2 - scalingRect), QPoint(X2 + scalingRect, Y2));
			rightScalRect = QRectF(QPoint(X1 - scalingRect, Y1), QPoint(X1, Y1 + scalingRect));
		}
	}
}

