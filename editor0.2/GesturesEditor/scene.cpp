#include "scene.h"

Scene::Scene() {
	this->mItemType = none;
	this->mCount = 0;
	this->mGraphicsItem = NULL;
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

void Scene::addNone(bool checked) {
	if (checked) {
		mItemType = none;
	}
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
	int x1 = event->scenePos().x();
	int y1 = event->scenePos().y();
	if (this->itemAt(event->scenePos()) == NULL)
		qDebug() << "element is null" << event->scenePos();
//	foreach (QGraphicsItem *item, this->items()) {
//		qDebug() << "items scene pos" << item->pos();
//	}
	qDebug() << "items number" << this->items().count();
	switch (mItemType) {
	case ellipse:
		this->mEllipse = new Ellipse(x1, y1, x1, y1);
		this->addItem(this->mEllipse);
		break;
	case rectangle:
		this->mRect = new Rectangle(x1, y1, x1, y1);
		this->mRect->setVisible(true);
		this->addItem(this->mRect);
		break;
	case arc:
		// arc draws when mouse is pressed
		this->mCount++;
		// sets first point
		if (mCount == 1) {
			this->mArc = new Arc(x1, y1, x1, y1, x1, y1);
			this->addItem(this->mArc);
		}
		// arc drawing end
		if (mCount == 3) {
			this->mCount = 0;
		}
		break;
	case line:
		this->mLine = new Line(x1, y1, x1, y1);
//		this->mLine = new Line(x1, y1, x1 + 100, y1 + 100);
		this->addItem(mLine);
		break;
	case none:
		this->mGraphicsItem = dynamic_cast<Item *>(this->itemAt(event->scenePos()));
		if (mGraphicsItem != NULL) {
			this->forPressResize(event);
		};
		break;
	}
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseMoveEvent(event);
	switch (mItemType) {
	case ellipse:
		this->reshapeEllipse(event);
		break;
	case rectangle:
		this->reshapeRect(event);
		break;
	case arc:
		if (mCount == 1) {
			this->reshapeArc1(event);
		}
		if (mCount == 2) {
			this->reshapeArc2(event);
		}
		break;
	case line:
		this->reshapeLine(event);
		break;
	case none:
		break;
	}
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
	switch (mItemType) {
	case ellipse:
		this->reshapeEllipse(event);
		break;
	case rectangle:
		this->reshapeRect(event);
		break;
	case arc:
		if (mCount == 1) {
			this->reshapeArc1(event);
		}
		if (mCount == 2) {
			this->reshapeArc2(event);
			this->mCount = 0;
			emit resetHighlightAllButtons();
		}
		break;
	case line:
		this->reshapeLine(event);
		break;
	default:
		break;
	}

	if (mItemType != arc) {
		emit resetHighlightAllButtons();
	}
}

void Scene::reshapeLine(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mLine->setX2andY2(x2, y2);
	invalidate();
	update();
}

void Scene::reshapeRect(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mRect->setX2andY2(x2, y2);
	invalidate();
}

void Scene::reshapeEllipse(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mEllipse->setX2andY2(x2, y2);
	invalidate();
}

void Scene::reshapeArc1(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mArc->setX2andY2(x2, y2);
	invalidate();
}

void Scene::reshapeArc2(QGraphicsSceneMouseEvent *event) {
	int x3 = event->scenePos().x();
	int y3 = event->scenePos().y();
	this->mArc->setCXandCY(x3, y3);
	invalidate();
}

void Scene::forPressResize(QGraphicsSceneMouseEvent *event)
{
	mGraphicsItem->changeDragState(event->scenePos().x(), event->scenePos().y());
}

void Scene::reshapeItem(QGraphicsSceneMouseEvent *event)
{
	if (mGraphicsItem != NULL) {
		mGraphicsItem->resizeItem(event);
	}
}

void Scene::forMoveResize(QGraphicsSceneMouseEvent *event)
{
	reshapeItem(event);
	this->update();
}

void Scene::forReleaseResize(QGraphicsSceneMouseEvent * event )
{
	this->reshapeItem(event);
	mGraphicsItem = NULL;
	this->update();
}

