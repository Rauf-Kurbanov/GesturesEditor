#include "scene.h"
Scene::Scene()
{
	this->mPen = new QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
}

void Scene::drawLine() {
<<<<<<< HEAD
	QGraphicsLineItem *coolLine = new QGraphicsLineItem(10, 20, 40, 60, NULL, this);
	//QGraphicsLineItem *line = this->addLine(QLineF(10, 10, 200, 120), *this->mPen);
=======
	QPen pen();
	QGraphicsLineItem *line = this->addLine(QLineF(10, 10, 200, 120), *this->mPen);

>>>>>>> 5c3c3efa6f3f2dcd8c00e117b6b2a5dab90477d7
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
