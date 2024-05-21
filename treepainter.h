#ifndef TREEPAINTER_H
#define TREEPAINTER_H

#include <QWidget>
#include <QGraphicsScene>
#include "brtree.h"
namespace Ui {
class TreePainter;
}

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
class TreePainter : public QWidget
{
    Q_OBJECT

public:
    explicit TreePainter(QWidget *parent = nullptr);
    ~TreePainter() override;
    void setTree(BRTree *tree);

    void add(int i);

    void remove(int i);
    void clear();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawNode(QPainter* painter, BRTree::Node *node, int x, int y, int hGap, int vGap);

private:
    Ui::TreePainter *ui;
    BRTree *brTree;
    QGraphicsScene *scene;


};

#endif // TREEPAINTER_H
