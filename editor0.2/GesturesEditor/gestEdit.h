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
};

#endif // GESTEDIT_H
