#include "gestEdit.h"
#include "ui_gestEdit.h"

GestEdit::GestEdit(QWidget *parent) :
	QWidget(parent),
	mUi(new Ui::GestEdit)
{
	mUi->setupUi(this);
	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));
	this->mScene = new Scene();
	this->mScene->setSceneRect(0, 0, this->width, this->height);
	mUi->graphicsView->setRenderHint(QPainter::Antialiasing, true);
	mUi->graphicsView->setScene(this->mScene);

}

void GestEdit::drawLine(bool checked)
{
	mScene->drawLine(checked);
}

GestEdit::~GestEdit()
{
	delete mUi;
}
