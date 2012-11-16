#ifndef GESTEDIT_H
#define GESTEDIT_H

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

private slots:
	void drawLine(bool checked);
};

#endif // GESTEDIT_H
