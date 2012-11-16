/********************************************************************************
** Form generated from reading UI file 'gestEditor.ui'
**
** Created: Thu 15. Nov 03:58:40 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTEDITOR_H
#define UI_GESTEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestEditor
{
public:
    QGraphicsView *graphicsView;
    QPushButton *drawLineButton;

    void setupUi(QWidget *GestEditor)
    {
        if (GestEditor->objectName().isEmpty())
            GestEditor->setObjectName(QString::fromUtf8("GestEditor"));
        GestEditor->resize(672, 465);
        graphicsView = new QGraphicsView(GestEditor);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(165, 0, 511, 471));
        drawLineButton = new QPushButton(GestEditor);
        drawLineButton->setObjectName(QString::fromUtf8("drawLineButton"));
        drawLineButton->setGeometry(QRect(20, 10, 75, 23));

        retranslateUi(GestEditor);

        QMetaObject::connectSlotsByName(GestEditor);
    } // setupUi

    void retranslateUi(QWidget *GestEditor)
    {
        GestEditor->setWindowTitle(QApplication::translate("GestEditor", "GestEditor", 0, QApplication::UnicodeUTF8));
        drawLineButton->setText(QApplication::translate("GestEditor", "line", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GestEditor: public Ui_GestEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTEDITOR_H
