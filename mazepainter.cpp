#include "mazepainter.h"
#include "ui_mazepainter.h"
#include <QResizeEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <queue>
#include <iostream>
#include <thread>
#include <algorithm>
#include <random>
MazePainter::MazePainter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MazePainter)
{
    ui->setupUi(this);
    isStop = false;
    isPressed = false;
    initMaze();
    time = 0;
}

MazePainter::~MazePainter()
{
    if (this->thread != nullptr) {
        this->thread->join();
    }
    delete ui;
}

void MazePainter::paintPoint(int x, int y) {
    if (x < 0 || y < 0) {
        return;
    }
    if (x >= SIZE || y >= SIZE) {
        return;
    }
    if (maze[x][y] != WALL && maze[x][y] != EMPTY) {
        return;
    }

    if (isLeftButtonPressed) {
        maze[x][y] = WALL;
        update();
    } else {
        maze[x][y] = EMPTY;
        update();
    }

}

void MazePainter::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    isPressed = true;
    isLeftButtonPressed = event->button() == Qt::LeftButton;
    auto w = this->width();
    auto per = w / SIZE;
    auto pos = event->pos();
    auto x = pos.x() / per;
    auto y = pos.y() / per;
    paintPoint(x, y);
//    if (x >= SIZE || y >= SIZE) {
//        return;
//    }
//    switch (maze[x][y]) {
//        case EMPTY:
//            maze[x][y] = WALL;
//            update();
//            break;
//        case WALL:
//            maze[x][y] = EMPTY;
//            update();
//            break;
//        case FOOTPRINT:
//            return;
//    }
}

void MazePainter::paintEvent(QPaintEvent *event) {
    auto w = this->width();
    auto per = w / SIZE;

    QPainter painter(this);
    painter.setPen(Qt::black);

    QVector<QLine> lines;
    for (int i = 0; i <= SIZE; ++i) {
        for (int j = 0; j <= SIZE; ++j) {

            lines.emplace_back(per * i, 0, per * i, per * SIZE);
            lines.emplace_back(0, per * i, per * SIZE, per * i);
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            QBrush brush;
            switch (maze[i][j]) {
                case WALL:
                    brush = QBrush(Qt::black);
                    break;
                case FOOTPRINT:
                    brush = QBrush(Qt::green);
                    break;
                case EMPTY:
                    brush = QBrush(Qt::gray);
                    break;
                case END:
                    brush = QBrush(Qt::red);
            }
            painter.fillRect(per * i, per * j , per, per, brush);
        }
    }
    painter.drawLines(lines);
}

void MazePainter::resizeEvent(QResizeEvent *event) {
    QSize size = dynamic_cast<QWidget *>(this->parent())->size();

    auto temp = std::min(size.height(), size.width());
    size.setHeight(temp);
    size.setWidth(temp);
    QWidget::resizeEvent(event);
}

void MazePainter::initMaze() {
    isStop = true;
    for (auto &item: maze) {
        for (auto &i: item) {
            i = EMPTY;
        }
    }
    maze[0][0] = FOOTPRINT;
    maze[SIZE - 1][SIZE - 1] = END;
    update();
}

void MazePainter::initMazeWithoutDestroyWall() {
    isStop = true;
    for (auto &item: maze) {
        for (auto &i: item) {
            if (i == FOOTPRINT) {
                i = EMPTY;
            }
        }
    }
    maze[0][0] = FOOTPRINT;
    maze[SIZE - 1][SIZE - 1] = END;
    update();
}

// 判断一个点是否在迷宫范围内
bool MazePainter::isValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// BFS寻路
bool MazePainter::bfs(Point start) {
    std::queue<Point> q;
    // 四个方向：上、下、左、右
    std::array<Point, 4> directions = {Point{-1, 0}, Point{1, 0}, Point{0, -1}, Point{0, 1}};

    q.push(start);
    maze[start.x][start.y] = FOOTPRINT;

    while (!q.empty()) {
        if (isStop) {
            return false;
        }
        Point current = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int newX = current.x + dir.x;
            int newY = current.y + dir.y;
            if (maze[newX][newY] == END) {
                return true;
            }
            if (isValid(newX, newY) && !maze[newX][newY] && maze[newX][newY] != WALL) {



                q.push({newX, newY});
                maze[newX][newY] = FOOTPRINT;

                if (maze[newX][newY] == EMPTY) {
                    maze[newX][newY] = FOOTPRINT;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        update();
    }

    return false;
}

void MazePainter::bfsFind() {
    thread = new std::thread([this] {
        bfs({0, 0});
        emit finished();
        delete this->thread;
        this->thread = nullptr;
    });
    thread->detach();
}

const std::array<std::pair<int, int>, 4> directions = {{
                                                               {1, 0}, {0, 1}, {-1, 0}, {0, -1}
}};
std::vector<std::pair<int, int>> abst = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool MazePainter::dfs(int x, int y, bool abstract) {
    if (isStop) {
        return false;
    }
    time++;
    // 越界检查
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return false;
    // 如果遇到墙或者已经走过，返回 false
    if (maze[x][y] == WALL || maze[x][y] == FOOTPRINT) return false;
    // 如果到达终点，返回 true
    if (maze[x][y] == END) return true;

    // 标记当前点为走过的足迹
    maze[x][y] = FOOTPRINT;

    if (time < 500 && time >= 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        update();
    } else if (time % 1000 == 0) {
        update();
    }
    if (abstract) {

        std::shuffle(abst.begin(), abst.end(), std::random_device());
        for (const auto& dir : abst) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (dfs(newX, newY, abstract)) {
                return true;
            }
        }
    } else{
        // 遍历四个方向
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (dfs(newX, newY, abstract)) {
                return true;
            }
        }
    }


    // 回溯，撤销足迹
    maze[x][y] = EMPTY;

    return false;
}

void MazePainter::dfsFind(bool abstract) {
    maze[0][0] = EMPTY;
    time = 0;
    thread = new std::thread([this, abstract] {

        dfs(0, 0, abstract);
        emit finished();
        update();
        delete this->thread;
        this->thread = nullptr;
    });
    thread->detach();
}


void MazePainter::aStarFind() {
    thread = new std::thread([this] {

        auto path = aStar(0, 0, SIZE - 1, SIZE - 1);
        markPath(path);
        emit finished();
        delete this->thread;
        this->thread = nullptr;
    });
    thread->detach();
}













// A*


int MazePainter::heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // 曼哈顿距离
}

std::vector<std::pair<int, int>> MazePainter::reconstructPath(Node* node) {
    std::vector<std::pair<int, int>> path;
    while (node) {
        path.emplace_back(node->x, node->y);
        node = node->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<std::pair<int, int>> MazePainter::aStar(int startX, int startY, int endX, int endY) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    std::vector<std::vector<bool>> closedSet(SIZE, std::vector<bool>(SIZE, false));

    Node startNode(startX, startY, 0, heuristic(startX, startY, endX, endY));
    openSet.push(startNode);

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();
        if (isStop) {
            return {};
        }

        if (current.x == endX && current.y == endY) {
            return reconstructPath(&current);
        }

        closedSet[current.x][current.y] = true;

        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && maze[newX][newY] != WALL && !closedSet[newX][newY]) {
                int newG = current.g + 1;
                int newH = heuristic(newX, newY, endX, endY);
                Node neighbor(newX, newY, newG, newH, new Node(current));

                if (!closedSet[newX][newY]) {
                    openSet.push(neighbor);
                }
            }
        }
    }

    return {}; // 如果没有找到路径，返回空路径
}

void MazePainter::markPath(const std::vector<std::pair<int, int>>& path) {

    for (const auto& p : path) {
        if (isStop) {
            return;
        }
        if (maze[p.first][p.second] == EMPTY) {
            maze[p.first][p.second] = FOOTPRINT;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update();
    }
}

void MazePainter::mouseReleaseEvent(QMouseEvent *event) {
    isPressed = false;
    isLeftButtonPressed = event->button() != Qt::LeftButton;
    QWidget::mouseReleaseEvent(event);
}

void MazePainter::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if (!isPressed) {
        return;
    }
    auto w = this->width();
    auto per = w / SIZE;
    auto pos = event->pos();
    auto x = pos.x() / per;
    auto y = pos.y() / per;
    paintPoint(x, y);
}


