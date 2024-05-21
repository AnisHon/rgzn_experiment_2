#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}

//#include <brtree.h>
//
//int main() {
//    BRTree brTree;
//    for (int i = 0; i < 5; ++i) {
//        brTree.put(i);
//    }
//    brTree.dlr_print();
//    return 0;
//}