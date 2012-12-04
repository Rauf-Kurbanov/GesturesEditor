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
	initButtonGroup();

	connect(mUi->drawLineButton, SIGNAL(clicked(bool)), this, SLOT(drawLine(bool)));
	connect(mUi->drawRectButton, SIGNAL(clicked(bool)), this, SLOT(drawRect(bool)));
	connect(mUi->drawEllipseButton, SIGNAL(clicked(bool)), this, SLOT(drawEllipse(bool)));
	connect(mUi->drawArcButton, SIGNAL(clicked(bool)), this, SLOT(drawArc(bool)));
	connect(mUi->clearButton, SIGNAL(clicked()), this, SLOT(clear()));
	connect(mUi->openButton, SIGNAL(clicked()), this, SLOT(open()));
	connect(mUi->saveButton, SIGNAL(clicked()), this, SLOT(save()));

	connect(mScene, SIGNAL(resetHighlightAllButtons()), this, SLOT(resetHighlightAllButtons()));
}

void GestEdit::initButtonGroup()
{
	mButtonGroup.append(mUi->drawLineButton);
	mButtonGroup.append(mUi->drawEllipseButton);
	mButtonGroup.append(mUi->drawArcButton);
	mButtonGroup.append(mUi->drawRectButton);
}

void GestEdit::setHighlightOneButton(QAbstractButton *oneButton)
{
	foreach (QAbstractButton *button, mButtonGroup) { //тут надо проверить по стайлгайду
		if (button != oneButton)
			button->setChecked(false);
	}
}

void GestEdit::resetHighlightAllButtons()
{
	foreach (QAbstractButton *button, mButtonGroup) {
		button->setChecked(false);
	}
	mScene->addNone(true);
}

void GestEdit::drawLine(bool checked)
{
	mScene->drawLine(checked);
	if (checked)
		setHighlightOneButton(mUi->drawLineButton);
}

void GestEdit::drawRect(bool checked)
{
	mScene->drawRect(checked);
	if (checked)
		setHighlightOneButton(mUi->drawRectButton);
}

void GestEdit::drawEllipse(bool checked)
{
	mScene->drawEllipse(checked);
	if (checked)
		setHighlightOneButton(mUi->drawEllipseButton);
}

void GestEdit::drawArc(bool checked)
{
	mScene->drawArc(checked);
	if (checked)
		setHighlightOneButton(mUi->drawArcButton);
}

void GestEdit::clear() {
	mScene->refresh();
	mScene->invalidate();
}

void GestEdit::open() {}

void GestEdit::save() {}

GestEdit::~GestEdit()
{
	delete mUi;
}
