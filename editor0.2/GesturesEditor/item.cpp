#include "item.h"

Item::Item(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) :
	QGraphicsItem(parent){
	this->mX1 = x1;
	this->mY1 = y1;
	this->mX2 = x2;
	this->mY2 = y2;
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsMovable, true);
	this->mPen = QPen(Qt::darkGray, 3, Qt::SolidLine, Qt::RoundCap);
	this->mBrush = QBrush(Qt::SolidPattern);
	this->mBrush.setColor(Qt::red);
	QPoint topLeft = QPoint(this->mX1, this->mY1);
	QPoint bottomRight = QPoint(this->mX2, this->mY2);
	this->mBoundingRect = QRectF(topLeft, bottomRight);
}

void Item::setX1andY1(qreal x, qreal y) {
	this->mX1 = x;
	this->mY1 = y;
}

void Item::setX2andY2(qreal x, qreal y) {
	this->mX2 = x;
	this->mY2 = y;
}

void Item::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(mPen);
	painter->setBrush(mBrush);
//	drawItem(painter, option, widget);
//	if (option->state & QStyle::State_Selected) {
//		painter->save();
//		setPenBrushForExtraxtion(painter, option);
//		drawExtractionForItem(painter);
//		painter->restore();
//	}
}

void Item::drawScalingRects(QPainter *painter) {
	painter->drawRect(mX1, mY1, scalingRect, scalingRect);
	painter->drawRect(mX2, mY2, scalingRect, scalingRect);
}

//void Item::drawFieldForResizeItem(QPainter* painter)
//{
//	QRectF itemBoundingRect = this->mBoundingRect;
//	qreal x1 = itemBoundingRect.left();
//	qreal x2 = itemBoundingRect.right();
//	qreal y1 = itemBoundingRect.top();
//	qreal y2 = itemBoundingRect.bottom();

//	painter->drawRect(x1, y1, resizeDrift, resizeDrift);
//	painter->drawRect(x2 - resizeDrift, y2 - resizeDrift, resizeDrift, resizeDrift);
//	painter->drawRect(x1, y2 - resizeDrift, resizeDrift, resizeDrift);
//	painter->drawRect(x2 - resizeDrift, y1, resizeDrift, resizeDrift);
//}
