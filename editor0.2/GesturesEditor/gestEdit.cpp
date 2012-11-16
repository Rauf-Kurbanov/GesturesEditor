#include "gestEdit.h"
#include "ui_gestEdit.h"

GestEdit::GestEdit(QWidget *parent) :
	QWidget(parent),
	mUi(new Ui::GestEdit)
{
	mUi->setupUi(this);
	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));

}

GestEdit::~GestEdit()
{
	delete mUi;
}
