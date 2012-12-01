#include "item.h"

Item::Item(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) :
	QGraphicsItem(parent)
{
	this->mX1 = x1;
	this->mY1 = y1;
	this->mX2 = x2;
	this->mY2 = y2;
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsMovable, true);
	this->mPen = QPen(Qt::darkGray, 3, Qt::SolidLine, Qt::RoundCap);
	this->mBrush = QBrush(Qt::SolidPattern);
	this->modifyBoundingRect();
}

void Item::setX1andY1(qreal x, qreal y) {
	this->mX1 = x;
	this->mY1 = y;
}

void Item::setX2andY2(qreal x, qreal y) {
	this->mX2 = x;
	this->mY2 = y;
}

void Item::setX1andY2(qreal x, qreal y)
{
	this->mX1 = x;
	this->mY2 = y;
}

void Item::setX2andY1(qreal x, qreal y)
{
	this->mX2 = x;
	this->mY1 = y;
}

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

void Item::drawScalingRects(QPainter *painter) {
	painter->drawRect(mX1, mY1, scalingRect, scalingRect);
	painter->drawRect(mX2, mY2, scalingRect, scalingRect);
}

// after element drawing mBoungintRect should be modified
void Item::modifyBoundingRect() {
	QPoint topLeft = QPoint(this->mX1, this->mY1);
	QPoint bottomRight = QPoint(this->mX2, this->mY2);
	this->mBoundingRect = QRectF(topLeft, bottomRight);
}

void Item::resizeItem(QGraphicsSceneMouseEvent *event)
{
	if (mDragState != None)
		this->calcResizeItem(event);
	else {
//		this->setFlag(QGraphicsItem::ItemIsMovable, true);
	}
}

void Item::changeDragState(qreal x, qreal y)
{
//	if (QRectF(QPointF(mX1 + scenePos().x(), mY1 + scenePos().y()), QSizeF(0, 0)).adjusted(-resizeDrift, -resizeDrift, resizeDrift, resizeDrift).contains(QPointF(x, y)))
//		mDragState = TopLeft;
//	else if (QRectF(QPointF(mX2 + scenePos().x(), mY2 + scenePos().y()), QSizeF(0, 0)).adjusted(-resizeDrift, -resizeDrift, resizeDrift, resizeDrift).contains(QPointF(x, y)))
//		mDragState = BottomRight;
//	else if (QRectF(QPointF(mX2 + scenePos().x(), mY1 + scenePos().y()), QSizeF(0, 0)).adjusted(-resizeDrift, -resizeDrift, resizeDrift, resizeDrift).contains(QPointF(x, y)))
//		mDragState = TopRight;
//	else if (QRectF(QPointF(mX1 + scenePos().x(), mY2 + scenePos().y()), QSizeF(0, 0)).adjusted(-resizeDrift, -resizeDrift, resizeDrift, resizeDrift).contains(QPointF(x, y)))
//		mDragState = BottomLeft;
//	else
//		mDragState = None;
//	if (this->boundingRect().contains(x, y)) {
//		this->mDragState = TopLeft;
//	}
	this->mPen.setColor(Qt::green);
}

void Item::calcResizeItem(QGraphicsSceneMouseEvent *event)
{
	qreal x = 0;// = mapFromScene(event->scenePos()).x();
	qreal y = 0; // mapFromScene(event->scenePos()).y();
//	if (mDragState != None)
//		setFlag(QGraphicsItem::ItemIsMovable, false);
	if (mDragState == TopLeft) {
		setX1andY1(x, y);
	};
//	else if (mDragState == TopRight) {
//		setX2andY1(x, y);
//	} else if (mDragState == BottomLeft) {
//		setX1andY2(x, y);
//	} else if (mDragState == BottomRight) {
//		setX2andY2(x, y);
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
