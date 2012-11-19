#include "gestEdit.h"
#include "ui_gestEdit.h"

GestEdit::GestEdit(QWidget *parent) :
	QWidget(parent),
	mUi(new Ui::GestEdit)
{
	mUi->setupUi(this);
	this->mScene = new Scene();
	this->mScene->setSceneRect(0, 0, this->width, this->height);
	mUi->graphicsView->setRenderHint(QPainter::Antialiasing, true);
	mUi->graphicsView->setScene(this->mScene);

	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));
	connect(mUi->drawRectButton, SIGNAL(clicked(bool)), this, SLOT(drawRect(bool)));
	connect(mUi->drawEllipseButton, SIGNAL(clicked(bool)), this, SLOT(drawEllipse(bool)));
	connect(mUi->drawArcButton, SIGNAL(clicked(bool)), this, SLOT(drawArc(bool)));
}

void GestEdit::drawLine(bool checked)
{
	mScene->drawLine(checked);
}

void GestEdit::drawRect(bool checked)
{
	mScene->drawRect(checked);
}

void GestEdit::drawEllipse(bool checked)
{
	mScene->drawEllipse(checked);
}

void GestEdit::drawArc(bool checked)
{
	mScene->drawArc(checked);
}

GestEdit::~GestEdit()
{
	delete mUi;
}
