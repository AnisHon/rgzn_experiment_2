/********************************************************************************
** Form generated from reading UI file 'treepainter.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEPAINTER_H
#define UI_TREEPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreePainter
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *TreePainter)
    {
        if (TreePainter->objectName().isEmpty())
            TreePainter->setObjectName("TreePainter");
        TreePainter->resize(400, 300);
        verticalLayout = new QVBoxLayout(TreePainter);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(TreePainter);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);


        retranslateUi(TreePainter);

        QMetaObject::connectSlotsByName(TreePainter);
    } // setupUi

    void retranslateUi(QWidget *TreePainter)
    {
        TreePainter->setWindowTitle(QCoreApplication::translate("TreePainter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreePainter: public Ui_TreePainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEPAINTER_H
