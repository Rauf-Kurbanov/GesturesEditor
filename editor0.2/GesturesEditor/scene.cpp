#include "scene.h"

Scene::Scene() {
	this->mPen = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
	this->mItemType = none;
}

void Scene::drawLine(bool checked) {
	if (checked)
		mItemType = line;
}

void Scene::drawRect(bool checked) {
	if (checked)
		mItemType = rectangle;
}

void Scene::drawEllipse(bool checked) {
	if (checked)
		mItemType = ellipse;
}

void Scene::drawArc(bool checked) {
	if (checked)
		mItemType = arc;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);

	switch (mItemType) {
//	case none:
//		return;
	case ellipse:
		break;
	case rectangle:
		break;
	case arc:
		break;
	case line :
		int x1 = event->scenePos().x();
		int y1 = event->scenePos().y();
		this->mLine = new Line(x1, y1, x1 + 1, y1 + 1);
		this->mLine->setVisible(true);
		this->addItem(this->mLine);
		break;
	}
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
	switch (mItemType) {
	case ellipse:
		break;
	case rectangle:
		break;
	case arc:
		break;
	 case line:
		this->reshapeLine(event);
		break;
	default:
		mItemType = none;
	}
}

void Scene::mouseMoveEvent( QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseMoveEvent(event);
	switch (mItemType) {
	case ellipse:
		break;
	case rectangle:
		break;
	case arc:
		break;
	 case line:
		this->reshapeLine(event);
		break;
	}
}

void Scene::reshapeLine(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mLine->setX2andY2(x2, y2);
	invalidate();
}
