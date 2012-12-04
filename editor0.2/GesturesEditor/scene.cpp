#include "scene.h"

Scene::Scene() {
	this->mItemType = none;
	this->mCount = 0;
	this->mGraphicsItem = NULL;
}

void Scene::drawLine(bool checked) {
	if (checked) {
		mItemType = line;
		stateSelection();
	}
}

void Scene::drawRect(bool checked) {
	if (checked) {
		mItemType = rectangle;
		stateSelection();
	}
}

void Scene::drawEllipse(bool checked) {
	if (checked) {
		mItemType = ellipse;
		stateSelection();
	}
}

void Scene::drawArc(bool checked) {
	if (checked) {
		mItemType = arc;
		stateSelection();
	}
}

void Scene::addNone(bool checked) {
	if (checked)
		mItemType = none;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
	stateSelection();
	stateMove();
	int x1 = event->scenePos().x();
	int y1 = event->scenePos().y();
	switch (mItemType) {
	case ellipse:
		this->mEllipse = new Ellipse(x1, y1, x1 + delta, y1 + delta);
		this->addItem(this->mEllipse);
		break;
	case rectangle:
		this->mRect = new Rectangle(x1, y1, x1 + delta, y1 + delta);
		this->addItem(this->mRect);
		break;
	case arc:
		// arc draws when mouse is pressed
		this->mCount++;
		if (mCount == 1) {
			this->mArc = new Arc(x1, y1, x1, y1, x1, y1);
			this->addItem(this->mArc);
		}
		break;
	case line:
		this->mLine = new Line(x1, y1, x1 + delta, y1 + delta);
		this->addItem(mLine);
		break;
	case none:
		mGraphicsItem = dynamic_cast<Item *>(this->itemAt(event->scenePos()));
			break;
	}
	qDebug() << "items number" << this->items().count();
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
		invalidate();
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
			mCount = 0;
			this->mItemType = none;
			this->stateMove();
			emit resetHighlightAllButtons();
		}
		break;
	case line:
		this->reshapeLine(event);
		break;
	case none:
		invalidate();
		break;
	}

	// because of 2-step arc drawing
	if (mItemType != arc) {
		emit resetHighlightAllButtons();
		this->mItemType = none;
	}
}

void Scene::reshapeLine(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mLine->setX2andY2(x2, y2);
	invalidate();
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

// sets arc's position
void Scene::reshapeArc1(QGraphicsSceneMouseEvent *event) {
	int x2 = event->scenePos().x();
	int y2 = event->scenePos().y();
	this->mArc->setX2andY2(x2, y2);
	invalidate();
}

// sets arc's curvation
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
	this->update();
}

void Scene::stateMove() {
	if (mItemType != none) {
		foreach (QGraphicsItem *item, this->items()) {
			item->setFlag(QGraphicsItem::ItemIsMovable, false);
		}
	} else {
		foreach (QGraphicsItem *item, this->items()) {
			item->setFlag(QGraphicsItem::ItemIsMovable, true);
		}
	}
}

void Scene::stateSelection() {
	if (mItemType != none) {
		foreach (QGraphicsItem *item, this->items()) {
			item->setFlag(QGraphicsItem::ItemIsSelectable, false);
			mGraphicsItem = NULL;
		}
	} else {
		foreach (QGraphicsItem *item, this->items()) {
			item->setFlag(QGraphicsItem::ItemIsSelectable, true);
		}
	}
}

void Scene::refresh() {
	foreach (QGraphicsItem *item, this->items()) {
		this->removeItem(item);
	}
}

void Scene::deleteSelectedItem() {
	if (mGraphicsItem != NULL) {
		this->removeItem(mGraphicsItem);
	}
}
