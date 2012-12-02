#pragma once

#include <QGraphicsScene>
#include "line.h"
#include "arc.h"
#include "rectangle.h"
#include "ellipse.h"
//#include "../../qrutils/graphicsUtils/abstractScene.h"

class Scene : public QGraphicsScene
{
	Q_OBJECT

public:
	Scene();
	void drawLine(bool checked);
	void drawRect(bool checked);
	void drawEllipse(bool checked);
	void drawArc(bool checked);
	void addNone(bool checked);

signals:
	void resetHighlightAllButtons();
private:
	enum ItemTypes {
		none
		, line
		, rectangle
		, ellipse
		, arc
	};

	ItemTypes mItemType;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent *event);
	virtual void forPressResize(QGraphicsSceneMouseEvent *event);
	virtual void forMoveResize(QGraphicsSceneMouseEvent *event);
	virtual void forReleaseResize(QGraphicsSceneMouseEvent *event);
	void reshapeLine(QGraphicsSceneMouseEvent *event);
	void reshapeRect(QGraphicsSceneMouseEvent *event);
	void reshapeEllipse(QGraphicsSceneMouseEvent *event);
	void reshapeArc1(QGraphicsSceneMouseEvent *event);
	void reshapeArc2(QGraphicsSceneMouseEvent *event);
//	void setX2andY2(QGraphicsSceneMouseEvent *event);
	void reshapeItem(QGraphicsSceneMouseEvent *event);

	Item *mGraphicsItem;
	Line *mLine;
	Rectangle *mRect;
	Ellipse *mEllipse;
	Arc *mArc;
	int mCount;
	bool mWaitMove;

	static const double delta = 0.01;
};

