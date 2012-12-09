#pragma once

#include <QtXml/QDomDocument>
#include <QWidget>

#include <scene.h>
#include<xmlLoader.h>

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
	QList<QAbstractButton *> mButtonGroup;
	qreal mX1;
	qreal mX2;
	qreal mY1;
	qreal mY2;
	QDomDocument mDocument;

	static const int height = 340;
	static const int width = 450;

	void initButtonGroup();
	void setHighlightOneButton(QAbstractButton *oneButton);

private slots:
	void drawLine(bool checked);
	void drawRect(bool checked);
	void drawEllipse(bool checked);
	void drawArc(bool checked);
	void deleteItem();
	void clear();
	void open();
	void save();
	void resetHighlightAllButtons();
};

