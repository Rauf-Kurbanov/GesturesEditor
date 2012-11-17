#include "item.h"

Item::Item(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) :
	QGraphicsItem(parent){
	QPoint topLeft = QPoint(x1, y1);
	QPoint bottomRight = QPoint(x2, y2);
	this->mBoundingRect = QRect(topLeft, bottomRight);
	this->mX1 = x1;
	this->mY1 = y1;
	this->mX2 = x2;
	this->mY2 = y2;
}

void Item::setX1andY1(qreal x, qreal y) {
	this->mX1 = x;
	this->mY1 = y;
}

void Item::setX1andY2(qreal x, qreal y) {
	this->mX1 = x;
	this->mY2 = y;
}

void Item::setX2andY1(qreal x, qreal y) {
	this->mX2 = x;
	this->mY1 = y;
}

void Item::setX2andY2(qreal x, qreal y) {
	this->mX2 = x;
	this->mY2 = y;
}

//void Item::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//	QGraphicsItem::mousePressEvent(event);
//}

void Item::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(mPen);
	painter->setBrush(mBrush);
	drawItem(painter, option, widget);
//	if (option->state & QStyle::State_Selected) {
//		painter->save();
//		setPenBrushForExtraxtion(painter, option);
//		drawExtractionForItem(painter);
//		painter->restore();
//	}
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
