#include "gestEdit.h"
#include "ui_gestEdit.h"

GestEdit::GestEdit(QWidget *parent) :
	QWidget(parent),
	mUi(new Ui::GestEdit)
{
	mUi->setupUi(this);
	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));
}

void GestEdit::drawLine(bool checked)
{
	mScene->drawLine(checked);
}

GestEdit::~GestEdit()
{
	delete mUi;
}
