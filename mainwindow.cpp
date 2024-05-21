#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "treepainter.h"
#include <QCloseEvent>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    b->dlr_print();
    connect(ui->resetBtn, &QPushButton::clicked, ui->mazePainter, &MazePainter::initMaze);
    connect(ui->stopBtn, &QPushButton::clicked, ui->mazePainter, &MazePainter::initMazeWithoutDestroyWall);
    connect(ui->mazePainter, &MazePainter::finished, this, &MainWindow::find_finished);
    ui->stopBtn->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_brAddBtn_clicked()
{
    ui->treePainter->add(ui->brAddSpinBox->value());
}


void MainWindow::on_brDelBtn_clicked()
{
    ui->treePainter->remove(ui->brDelSpinBox->value());
}


void MainWindow::on_clearBtn_clicked()
{
    ui->treePainter->clear();
}


void MainWindow::on_findBtn_clicked()
{
    ui->findBtn->setDisabled(true);
    ui->stopBtn->setDisabled(false);
    ui->mazePainter->initMazeWithoutDestroyWall();
    ui->mazePainter->isStop = false;

    switch (ui->option->currentIndex()) {
        case 0:
            ui->mazePainter->aStarFind();
            break;
        case 1:
            ui->mazePainter->dfsFind(false);
            break;
        case 2:
            ui->mazePainter->bfsFind();
            break;
        case 3:
            ui->mazePainter->dfsFind(true);
            break;
    }

}

void MainWindow::find_finished() {
    ui->findBtn->setDisabled(false);
    ui->stopBtn->setDisabled(true);
    ui->mazePainter->isStop = true;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);
//    qDebug() << ui->mazePainter->isStop;
    if (!ui->mazePainter->isStop) {
        event->ignore();
        QMessageBox::warning(this, "错误", "请停止寻路线程后再关闭");
        return;
    }
    event->accept();
}

