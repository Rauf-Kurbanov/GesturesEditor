#include "scene.h"
Scene::Scene()
{
	this->mPen = new QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
}

void Scene::drawLine() {
	QGraphicsLineItem *line = this->addLine(QLineF(10, 10, 200, 120), *this->mPen);

}

void Scene::drawEllipse() {
	QGraphicsEllipseItem *ellipse = this->addEllipse(QRectF (30, 30, 140, 170), *this->mPen);
}

void Scene::drawRectangle() {
	QGraphicsRectItem *rectangle = this->addRect(QRectF(50, 50, 200, 200), *this->mPen);

}

void Scene::clearScene() {
	this->clear();
}
