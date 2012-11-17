/********************************************************************************
** Form generated from reading UI file 'gestEdit.ui'
**
** Created: Sat 17. Nov 20:27:16 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTEDIT_H
#define UI_GESTEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestEdit
{
public:
    QGraphicsView *graphicsView;
    QPushButton *drawLineButton;

    void setupUi(QWidget *GestEdit)
    {
        if (GestEdit->objectName().isEmpty())
            GestEdit->setObjectName(QString::fromUtf8("GestEdit"));
        GestEdit->resize(706, 487);
        graphicsView = new QGraphicsView(GestEdit);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(225, 0, 481, 481));
        drawLineButton = new QPushButton(GestEdit);
        drawLineButton->setObjectName(QString::fromUtf8("drawLineButton"));
        drawLineButton->setGeometry(QRect(20, 20, 75, 23));

        retranslateUi(GestEdit);

        QMetaObject::connectSlotsByName(GestEdit);
    } // setupUi

    void retranslateUi(QWidget *GestEdit)
    {
        GestEdit->setWindowTitle(QApplication::translate("GestEdit", "GestEdit", 0, QApplication::UnicodeUTF8));
        drawLineButton->setText(QApplication::translate("GestEdit", "line", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GestEdit: public Ui_GestEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTEDIT_H
