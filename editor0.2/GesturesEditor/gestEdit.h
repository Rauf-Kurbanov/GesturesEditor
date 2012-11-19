#pragma once

#include <QWidget>
#include <scene.h>

namespace Ui {
class GestEdit;
}

class GestEdit : public QWidget
{
	Q_OBJECT

public:
	explicit GestEdit(QWidget *parent = 0);
	~GestEdit();

private:
	Ui::GestEdit *mUi;
	Scene *mScene;
	static const int height = 400;
	static const int width = 525;

private slots:
	void drawLine(bool checked);
	void drawRect(bool checked);
	void drawEllipse(bool checked);
	void drawArc(bool checked);
};

