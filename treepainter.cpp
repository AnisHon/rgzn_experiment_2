#include "treepainter.h"
#include "ui_treepainter.h"
#include <QPainter>
#include <QGraphicsScene>
TreePainter::TreePainter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TreePainter)
{
    ui->setupUi(this);
    brTree = new BRTree(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVisible(false);
}

TreePainter::~TreePainter()
{
    delete ui;
}

void TreePainter::drawNode(QPainter *painter, BRTree::Node *node, int x, int y, int hGap, int vGap) {
    int radius = 20;
    if (hGap < 20) {
        radius = hGap + 4;
    }
    if (!node) {
        return;
    }

    QPen pen(Qt::white);
    QBrush brush;

    // 递归绘制左子树
    if (node->left) {
        painter->drawLine(x, y, x - hGap, y + vGap);
        drawNode(painter, node->left, x - hGap, y + vGap, hGap / 2, vGap);
    }

    // 递归绘制右子树
    if (node->right) {
        painter->drawLine(x, y, x + hGap, y + vGap);
        drawNode(painter, node->right, x + hGap, y + vGap, hGap / 2, vGap);
    }

    qDebug() << node->element;

//    qDebug() << (BRTree::get_color(node) == BRTree::RED ? "red" : "black");
    switch (BRTree::get_color(node)) {

        case BRTree::RED:
            brush = QBrush(Qt::red);
            painter->setBrush(Qt::red);
            break;
        case BRTree::BLACK:
            brush = QBrush(Qt::black);
            painter->setBrush(Qt::black);
            break;
    }


//    scene->addEllipse(x, y, radius, radius, pen, brush);
//    scene->addText(QString::number(node->element));
//     绘制节点圆圈
    painter->drawEllipse(QPoint(x, y), radius, radius);
//     绘制节点值
    painter->drawText(QRect(x - radius, y - radius, 2 * radius, 2 * radius), Qt::AlignCenter, QString::number(node->element));

}

void TreePainter::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);  // 开启反锯齿
    int w = width();
    scene->clear();
    int hGap = brTree->getHeight() * 40;
    drawNode(&painter, brTree->getNode(), w / 2, 40, w / 4, 50);
}

void TreePainter::setTree(BRTree *tree) {
    brTree = tree;
}

void TreePainter::add(int i) {
    brTree->put(i);
    update();
}

void TreePainter::remove(int i) {
    if (brTree->getNode() == nullptr) {
        return;
    }
    brTree->erase(i);
    update();
}

void TreePainter::clear() {
    delete brTree;
    brTree = new BRTree();
    update();
}


