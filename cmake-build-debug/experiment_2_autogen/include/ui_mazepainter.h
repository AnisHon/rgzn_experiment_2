/********************************************************************************
** Form generated from reading UI file 'mazepainter.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZEPAINTER_H
#define UI_MAZEPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazePainter
{
public:

    void setupUi(QWidget *MazePainter)
    {
        if (MazePainter->objectName().isEmpty())
            MazePainter->setObjectName("MazePainter");
        MazePainter->resize(400, 300);

        retranslateUi(MazePainter);

        QMetaObject::connectSlotsByName(MazePainter);
    } // setupUi

    void retranslateUi(QWidget *MazePainter)
    {
        MazePainter->setWindowTitle(QCoreApplication::translate("MazePainter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazePainter: public Ui_MazePainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZEPAINTER_H
