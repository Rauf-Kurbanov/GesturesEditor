#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QWidget>
#include <scene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
    void clearScene();
    void drawRectangle();
    void drawEllipse();
    void drawLine();

private:
	Ui::MainWindow *ui;
    Scene *mScene;
};

#endif // MAINWINDOW_H
