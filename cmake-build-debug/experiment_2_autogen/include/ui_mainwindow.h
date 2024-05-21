/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mazepainter.h"
#include "treepainter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *brAddSpinBox;
    QPushButton *brAddBtn;
    QSpinBox *brDelSpinBox;
    QPushButton *brDelBtn;
    QPushButton *clearBtn;
    QSpacerItem *horizontalSpacer;
    TreePainter *treePainter;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    MazePainter *mazePainter;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QComboBox *option;
    QPushButton *findBtn;
    QPushButton *stopBtn;
    QPushButton *resetBtn;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideRight);
        tabWidget->setDocumentMode(false);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        brAddSpinBox = new QSpinBox(groupBox);
        brAddSpinBox->setObjectName("brAddSpinBox");
        brAddSpinBox->setMinimumSize(QSize(75, 0));
        brAddSpinBox->setMinimum(-1000);
        brAddSpinBox->setMaximum(1000);

        horizontalLayout_2->addWidget(brAddSpinBox);

        brAddBtn = new QPushButton(groupBox);
        brAddBtn->setObjectName("brAddBtn");

        horizontalLayout_2->addWidget(brAddBtn);

        brDelSpinBox = new QSpinBox(groupBox);
        brDelSpinBox->setObjectName("brDelSpinBox");
        brDelSpinBox->setMinimumSize(QSize(75, 0));
        brDelSpinBox->setMinimum(-1000);
        brDelSpinBox->setMaximum(1000);

        horizontalLayout_2->addWidget(brDelSpinBox);

        brDelBtn = new QPushButton(groupBox);
        brDelBtn->setObjectName("brDelBtn");

        horizontalLayout_2->addWidget(brDelBtn);

        clearBtn = new QPushButton(groupBox);
        clearBtn->setObjectName("clearBtn");

        horizontalLayout_2->addWidget(clearBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBox);

        treePainter = new TreePainter(tab);
        treePainter->setObjectName("treePainter");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(treePainter->sizePolicy().hasHeightForWidth());
        treePainter->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(treePainter);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 12, -1, 12);
        mazePainter = new MazePainter(tab_2);
        mazePainter->setObjectName("mazePainter");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(mazePainter->sizePolicy().hasHeightForWidth());
        mazePainter->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(mazePainter);


        horizontalLayout_3->addLayout(verticalLayout_3);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMaximumSize(QSize(150, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        option = new QComboBox(groupBox_2);
        option->addItem(QString());
        option->addItem(QString());
        option->addItem(QString());
        option->addItem(QString());
        option->setObjectName("option");

        verticalLayout_2->addWidget(option);

        findBtn = new QPushButton(groupBox_2);
        findBtn->setObjectName("findBtn");

        verticalLayout_2->addWidget(findBtn);

        stopBtn = new QPushButton(groupBox_2);
        stopBtn->setObjectName("stopBtn");

        verticalLayout_2->addWidget(stopBtn);

        resetBtn = new QPushButton(groupBox_2);
        resetBtn->setObjectName("resetBtn");

        verticalLayout_2->addWidget(resetBtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(groupBox_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(brDelSpinBox, &QSpinBox::editingFinished, brDelBtn, qOverload<>(&QPushButton::click));
        QObject::connect(brAddSpinBox, &QSpinBox::editingFinished, brAddBtn, qOverload<>(&QPushButton::click));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        brAddBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        brDelBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\272\242\351\273\221\346\240\221", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        option->setItemText(0, QCoreApplication::translate("MainWindow", "A*\346\234\200\344\274\230\345\257\273\350\267\257", nullptr));
        option->setItemText(1, QCoreApplication::translate("MainWindow", "dfs\346\267\261\345\272\246\344\274\230\345\205\210", nullptr));
        option->setItemText(2, QCoreApplication::translate("MainWindow", "bfs\345\271\277\345\272\246\344\274\230\345\205\210", nullptr));
        option->setItemText(3, QCoreApplication::translate("MainWindow", "\346\212\275\350\261\241\346\250\241\345\274\217", nullptr));

        findBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\257\273\350\267\257", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\345\257\273\350\267\257", nullptr));
        resetBtn->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\257\273\350\267\257\347\256\227\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
