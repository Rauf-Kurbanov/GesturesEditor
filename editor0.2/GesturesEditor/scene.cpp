#include "scene.h"

Scene::Scene()
{
	this->mPen = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
}

void Scene::drawLine(bool checked) {
//	if (checked)
//		mItemType = line;
	this->addItem(&Line(40,40, 120, 120));
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsScene::mousePressEvent(event);
	/*
	setDragMode(mItemType);
	switch (mItemType) {
		case line :
			setX1andY1(event);
			mLine = new Line(mX1, mY1, mX1, mY1, NULL);
			mLine->setPenBrush(mPenStyleItems, mPenWidthItems, mPenColorItems, mBrushStyleItems, mBrushColorItems);
			addItem(mLine);
			setZValue(mLine);
			removeMoveFlag(event, mLine);
			mWaitMove = true;
			break;

	}*/
}
