#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(this->ui->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine()));
	connect(this->ui->drawEllipseButton, SIGNAL(clicked(bool)), this, SLOT(drawEllipse()));
	connect(this->ui->drawRectangleButton, SIGNAL(clicked(bool)), this, SLOT(drawRectangle()));
	connect(this->ui->clearButton, SIGNAL(clicked(bool)), this, SLOT(clearScene()));
	this->mScene = new Scene();
	this->mScene->setSceneRect(0, 0,this->width, this->height);
	ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
	ui->graphicsView->setScene(this->mScene);

}

void MainWindow::drawLine() {
	mScene->drawLine();
}

void MainWindow::drawEllipse() {
	mScene->drawEllipse();
}

void MainWindow::drawRectangle() {
	mScene->drawRectangle();
}

void MainWindow::clearScene() {
	mScene->clearScene();

}

MainWindow::~MainWindow()
{
	delete ui;
}
