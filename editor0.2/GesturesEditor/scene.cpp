#include "scene.h"

Scene::Scene() {
	this->mPen = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
}

void Scene::drawLine(bool checked) {
//	if (checked)
//		mItemType = line;
	Line *simpleLine = new Line(10, 10, 120, 120);
	this->addItem(simpleLine);
	simpleLine->setVisible(true);
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
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
	int x1 = event->scenePos().x();
	int y1 = event->scenePos().y();
	this->mLine = new Line(x1, y1, x1, y1);
	this->mLine->setVisible(true);
	this->addItem(this->mLine);

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
	this->reshapeLine(event);
}

void Scene::mouseMoveEvent( QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseMoveEvent(event);
	this->reshapeLine(event);
}

void Scene::reshapeLine(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mLine->setX2andY2(x2, y2);
}
