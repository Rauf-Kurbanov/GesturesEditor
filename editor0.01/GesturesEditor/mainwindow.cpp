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
	ui->graphicsView->setScene(this->mScene);

}

void MainWindow::drawLine() {
	Line *line = new Line();
	this->mScene->addItem(line);
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
