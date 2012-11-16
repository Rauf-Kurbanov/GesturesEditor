#include "scene.h"
Scene::Scene()
{
	this->mPen = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
}

void Scene::drawLine() {
	QGraphicsLineItem *line = this->addLine(QLineF(10, 10, 200, 120), this->mPen);
}

void Scene::drawEllipse() {
	QGraphicsEllipseItem *ellipse = this->addEllipse(QRectF (30, 30, 140, 170), this->mPen);
}

void Scene::drawRectangle() {
	QGraphicsRectItem *rectangle = this->addRect(QRectF(50, 50, 200, 200), this->mPen);

}

void Scene::clearScene() {
	this->clear();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
	int mX1 = event->scenePos().x();
	int mY1 = event->scenePos().y();
	this->mLine = this->addLine(mX1, mY1, mX1 + 50, mY1 + 50, this->mPen);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	this->reshapeLine(event);
}

void Scene::reshapeLine(QGraphicsSceneMouseEvent *event) {
	int mX1 = event->scenePos().x();
	int mY1 = event->scenePos().y();
	// add changes into end of a line;
	//mLine->setPos(mX1, mY1);
}
