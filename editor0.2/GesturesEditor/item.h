#pragma once
#include <QtGui>

//const int drift = 15;
//const int resizeDrift = 10;
//const int scalingDrift = 10;
const int scalingRect = 6;

class Item : public QGraphicsItem
{

public:
	Item(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);
	void setX1andY1(qreal x, qreal y);
	void setX2andY2(qreal x, qreal y);

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
	virtual void drawItem(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) = 0;
	virtual void drawScalingRects(QPainter* painter);
//	virtual void drawFieldForResizeItem(QPainter* painter);

protected:
	QRectF mBoundingRect;
	QPen mPen;
	QBrush mBrush;
	qreal mX1;
	qreal mY1;
	qreal mX2;
	qreal mY2;
};
