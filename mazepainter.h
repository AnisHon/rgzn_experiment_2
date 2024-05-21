#ifndef MAZEPAINTER_H
#define MAZEPAINTER_H

#include <QWidget>
#include <array>
#include <qvector2d.h>
#include <thread>

namespace Ui {
class MazePainter;
}

class MazePainter : public QWidget
{
    Q_OBJECT

    enum Type {
        EMPTY = 0, WALL, FOOTPRINT, END
    };

public:
    explicit MazePainter(QWidget *parent = nullptr);
    ~MazePainter();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

signals:
    void finished();

public slots:
    void initMaze();
    void initMazeWithoutDestroyWall();

    void bfsFind();
    void dfsFind(bool abstract);
    void aStarFind();

private:
    struct Point {
        int x, y;
    };


    struct Node {
        int x, y;
        int g, h;
        Node* parent;

        Node(int x, int y, int g, int h, Node* parent = nullptr)
                : x(x), y(y), g(g), h(h), parent(parent) {}

        int getF() const {
            return g + h;
        }

        bool operator>(const Node& other) const {
            return getF() > other.getF();
        }
    };



    bool bfs(Point start);
    bool isValid(int x, int y);
    bool dfs(int x, int y, bool abstract);
    void markPath(const std::vector<std::pair<int, int>>& path);
    std::vector<std::pair<int, int>> aStar(int startX, int startY, int endX, int endY);
    std::vector<std::pair<int, int>> reconstructPath(Node* node);
    int heuristic(int x1, int y1, int x2, int y2);

    void paintPoint(int x, int y);




public:
    bool isStop;
private:
    Ui::MazePainter *ui;
    bool isPressed;
    bool isLeftButtonPressed;
    static const int SIZE = 28;
    std::array<std::array<int, SIZE>, SIZE> maze;
    std::thread *thread;
    int time;

};

#endif // MAZEPAINTER_H
