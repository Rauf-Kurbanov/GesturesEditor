#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(this->ui->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));
}

void MainWindow::drawLine(bool checked) {
	mScene->drawLine(true);
}

MainWindow::~MainWindow()
{
	delete ui;
}
