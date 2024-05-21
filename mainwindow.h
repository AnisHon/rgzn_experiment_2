#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_brAddBtn_clicked();

    void on_brDelBtn_clicked();

    void on_clearBtn_clicked();

    void on_findBtn_clicked();

    void find_finished();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
