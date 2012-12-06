#include "rectangle.h"

Rectangle::Rectangle(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : Item(x1, y1, x2, y2) {
	QPoint firstPoint = QPoint(x1, y1);
	QPoint secondPoint = QPoint(x2, y2);
	updateScalingRects(firstPoint, secondPoint);
}

QRectF Rectangle::boundingRect() const {
	QPoint topLeft = QPoint(this->mX1, this->mY1);
	QPoint bottomRight = QPoint(this->mX2, this->mY2);
	return QRectF(topLeft, bottomRight);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	if (this->isSelected()) {
		this->drawScalingRects(painter);
	} else {
		painter->setPen(this->mPen);
		this->drawItem(painter, option, widget);
	}
}

void Rectangle::drawItem(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPoint topLeftPoint = QPoint(this->mX1, this->mY1);
	QPoint bottomRightPoint = QPoint(this->mX2, this->mY2);
	QRectF rectangle = QRectF(topLeftPoint, bottomRightPoint);
	painter->drawRect(rectangle);
}

void Rectangle::drawScalingRects(QPainter *painter) {
	painter->setPen(QPen(Qt::darkGray, 1, Qt::DashLine, Qt::RoundCap));
	painter->drawRect(this->boundingRect());
	painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
	painter->setBrush(this->mBrush);
	QRectF leftBottomScalRect;
	QRectF leftTopScalRect;
	QRectF rightTopScalRect;
	QRectF rightBottomScalRect;
	if (mX2 >= mX1) {
		if (mY2 >= mY1) {
			leftTopScalRect = QRectF(QPoint(mX1, mY1), QPoint(mX1 + scalingRect, mY1 + scalingRect));
			leftBottomScalRect = QRectF(QPoint(mX1, mY2 - scalingRect), QPoint(mX1 + scalingRect, mY2));
			rightBottomScalRect = QRectF(QPoint(mX2 - scalingRect, mY2 - scalingRect), QPoint(mX2, mY2));
			rightTopScalRect = QRectF(QPoint(mX2 - scalingRect, mY1), QPoint(mX2, mY1 + scalingRect));

		} else {
			leftBottomScalRect = QRectF(QPoint(mX1, mY1 - scalingRect), QPoint(mX1 + scalingRect, mY1));
			leftTopScalRect = QRectF(QPoint(mX1, mY2), QPoint(mX1 + scalingRect, mY2 + scalingRect));
			rightTopScalRect = QRectF(QPoint(mX2 - scalingRect, mY2), QPoint(mX2 , mY2 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(mX2 - scalingRect, mY1 - scalingRect), QPoint(mX2, mY1));
		}
	} else {
		if (mY2 <= mY1) {
			leftBottomScalRect = QRectF(QPoint(mX2, mY1 - scalingRect), QPoint(mX2 + scalingRect, mY1));
			leftTopScalRect = QRectF(QPoint(mX2, mY2), QPoint(mX2 + scalingRect, mY2 + scalingRect));
			rightTopScalRect = QRectF(QPoint(mX1 - scalingRect, mY2), QPoint(mX1 , mY2 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(mX1 - scalingRect, mY1 - scalingRect), QPoint(mX1, mY1));
		} else {
			leftBottomScalRect = QRectF(QPoint(mX2, mY2 - scalingRect), QPoint(mX2 + scalingRect, mY2));
			leftTopScalRect = QRectF(QPoint(mX2, mY1), QPoint(mX2 + scalingRect, mY1 + scalingRect));
			rightTopScalRect = QRectF(QPoint(mX1 - scalingRect, mY1), QPoint(mX1 , mY1 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(mX1 - scalingRect, mY2 - scalingRect), QPoint(mX1, mY2));
		}
	}
	painter->drawRect(leftTopScalRect);
	painter->drawRect(rightBottomScalRect);
	painter->drawRect(leftBottomScalRect);
	painter->drawRect(rightTopScalRect);
}

void Rectangle::changeDragState(qreal x, qreal y) {
	QPoint clickPoint = QPoint(x, y);
	if (leftTopScalRect.contains(clickPoint)) {
		mDragState = TopLeft;
	} else {
		if (leftBottomScalRect.contains(clickPoint)) {
			mDragState = BottomLeft;
		} else {
			if (rightTopScalRect.contains(clickPoint)) {
				mDragState = TopRight;
			} else {
				if (rightBottomScalRect.contains(clickPoint)) {
					mDragState = BottomRight;
				} else {
					mDragState = None;
				}
			}
		}
	}

}

void Rectangle::updateScalingRects(QPointF topLeft, QPointF bottomRight) {
	qreal X1 = topLeft.x();
	qreal Y1 = topLeft.y();
	qreal X2 = bottomRight.x();
	qreal Y2 = bottomRight.y();
	if (mX2 >= mX1) {
		if (mY2 >= mY1) {
			leftTopScalRect = QRectF(QPoint(X1, Y1), QPoint(X1 + scalingRect, Y1 + scalingRect));
			leftBottomScalRect = QRectF(QPoint(X1, Y2 - scalingRect), QPoint(X1 + scalingRect, Y2));
			rightBottomScalRect = QRectF(QPoint(X2 - scalingRect, Y2 - scalingRect), QPoint(X2, Y2));
			rightTopScalRect = QRectF(QPoint(X2 - scalingRect, Y1), QPoint(X2, Y1 + scalingRect));

		} else {
			leftBottomScalRect = QRectF(QPoint(X1, Y1 - scalingRect), QPoint(X1 + scalingRect, Y1));
			leftTopScalRect = QRectF(QPoint(X1, Y2), QPoint(X1 + scalingRect, Y2 + scalingRect));
			rightTopScalRect = QRectF(QPoint(X2 - scalingRect, Y2), QPoint(X2 , Y2 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(X2 - scalingRect, Y1 - scalingRect), QPoint(X2, Y1));
		}
	} else {
		if (Y2 <= Y1) {
			leftBottomScalRect = QRectF(QPoint(X2, Y1 - scalingRect), QPoint(X2 + scalingRect, Y1));
			leftTopScalRect = QRectF(QPoint(X2, Y2), QPoint(X2 + scalingRect, Y2 + scalingRect));
			rightTopScalRect = QRectF(QPoint(X1 - scalingRect, Y2), QPoint(X1 , Y2 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(X1 - scalingRect, Y1 - scalingRect), QPoint(X1, Y1));
		} else {
			leftBottomScalRect = QRectF(QPoint(X2, Y2 - scalingRect), QPoint(X2 + scalingRect, Y2));
			leftTopScalRect = QRectF(QPoint(X2, Y1), QPoint(X2 + scalingRect, Y1 + scalingRect));
			rightTopScalRect = QRectF(QPoint(X1 - scalingRect, Y1), QPoint(X1 , Y1 + scalingRect));
			rightBottomScalRect = QRectF(QPoint(X1 - scalingRect, Y2 - scalingRect), QPoint(X1, Y2));
		}
	}
}
