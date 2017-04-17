#ifndef ALIEN_H
#define ALIEN_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
class Alien: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    enum Direction {left, up, right, down};
    Alien(QGraphicsItem* parent = 0);
    Alien(int x, int y);
    Alien(int x, int y, Direction dX, Direction dY);
    Alien(int x, int y, Direction dX, Direction dY, int leftL, int upL, int rightL, int downL, int xLimit, int yLimit);
    virtual ~Alien();
    bool isGoingLeft();
    bool isGoingRight();
    bool isGoingUp();
    bool isGoingDown();
    int getXLim();
    int getYLim();
    int getRate();
    int getLeftLim();
    int getRightLim();
    int getUpLim();
    int getDownLim();
    void setXDirection(Direction d);
    void setYDirection(Direction d);
    void setXLim(int x);
    void setYLim(int y);
    void setRate(int r);
    void setLeftLim(int l);
    void setRightLim(int l);
    void setUpLim(int l);
    void setDownLim(int l);
    void setHeight(int h);
    void setWidth(int w);
    void start(int t);

    QPixmap getPic();
    void setPic(QPixmap p);

    QTimer* getTimer();

    int width();
    int height();


private:
    // x and y limits.
    int leftLim, rightLim, upLim, downLim;
    Direction xDir; // keep track of x-axis direction.
    Direction yDir; // kepp track of y-axis direction.
    int xLim; // refreshed x-axis limit.
    int yLim; // refreshed y-axis limit.

    QTimer* moveTimer; // timer for thread.
    QPixmap pic; // image for the aliens.

    int w_,h_;

    virtual bool checkCollisions();

public slots:
    virtual void move();
};

#endif // ALIEN_H
