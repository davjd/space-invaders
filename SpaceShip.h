#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSet>
//#include <QObject>


class SpaceShip: public QGraphicsPixmapItem{
public:
    // methods:
    SpaceShip(QGraphicsItem* parent = 0);
    bool sceneEvent(QEvent *event);
    int getWidth();
    int getHeight();
    void updateHealth(int h);
    int health();


private:
    QSet<int> pressedKeys;
    QTimer* timer;
    int health_;
    int height;
    int width;

};

#endif // SPACESHIP_H
