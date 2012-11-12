#include "scene.h"
Scene::Scene()
{
}

void Scene::drawLine() {

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
