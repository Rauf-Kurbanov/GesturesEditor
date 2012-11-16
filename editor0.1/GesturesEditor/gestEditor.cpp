#include "gestEditor.h"
#include "ui_gestEditor.h"

GestEditor::GestEditor(QWidget *parent) :
	QWidget(parent),
	mUi(new Ui::GestEditor)
{
	mUi->setupUi(this);
	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));

}

GestEditor::~GestEditor()
{
	delete mUi;
}
