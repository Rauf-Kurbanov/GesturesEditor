#pragma once
#include <QtGui>

const int drift = 15;
const int resizeDrift = 10;
const int scalingDrift = 10;
const int scalingRect = 2;
const int boundingGap = 2;

class Item : public QGraphicsItem
{

public:
	enum DragState {
		None,
		TopLeft,
		TopRight,
		BottomLeft,
		BottomRight
	};

//	enum DomElementTypes {
//		noneType,
//		pictureType,
//		labelType,
//		portType
//	};

	enum ScalingPointState {
		noneScale,
		topLeftX,
		topRightX,
		bottomLeftX,
		bottomRightX,
		topLeftY,
		topRightY,
		bottomLeftY,
		bottomRightY
	};

	Item(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);
	void setX1andY1(qreal x, qreal y);
	void setX2andY2(qreal x, qreal y);
	void setX1andY2(qreal x, qreal y);
	void setX2andY1(qreal x, qreal y);

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
	virtual void drawItem(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) = 0;
	virtual void drawScalingRects(QPainter* painter);
	virtual void resizeItem(QGraphicsSceneMouseEvent *event);
	virtual void calcResizeItem(QGraphicsSceneMouseEvent *event);
	virtual void changeDragState(qreal x, qreal y);
	virtual QRectF boundingRect() const;
//	virtual void drawFieldForResizeItem(QPainter* painter);

protected:
	DragState mDragState;
	QPen mPen;
	QBrush mBrush;
	qreal mX1;
	qreal mY1;
	qreal mX2;
	qreal mY2;
};
