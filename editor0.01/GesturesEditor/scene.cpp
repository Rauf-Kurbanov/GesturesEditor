#include "scene.h"
#include <QGraphicsView>
Scene::Scene()
{
}

void Scene::drawLine() {
	this->addLine(10, 10, 140, 240);
}

void Scene::drawEllipse() {
	this->addEllipse(20, 30, 120, 210);
}

void Scene::drawRectangle() {
	this->addRect(50,50, 170, 170);
}

void Scene::clearScene() {
	this->clear();
}
