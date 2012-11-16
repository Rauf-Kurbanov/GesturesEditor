#ifndef GESTEDITOR_H
#define GESTEDITOR_H

#include <QWidget>
#include <scene.h>

namespace Ui {
class GestEditor;
}

class GestEditor : public QWidget
{
	Q_OBJECT

public:
	explicit GestEditor(QWidget *parent = 0);
	~GestEditor();

private:
	Ui::GestEditor *mUi;
	Scene *mScene;
};

#endif // GESTEDITOR_H
