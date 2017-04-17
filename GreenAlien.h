#ifndef GREENALIEN_H
#define GREENALIEN_H

#include "Alien.h"
#include <QGraphicsItem>
#include <QObject>

class GreenAlien: public Alien{
    Q_OBJECT
public:
    GreenAlien(QGraphicsItem* parent = 0);
    GreenAlien(int x, int y);
    GreenAlien(int x, int y, Direction dX, Direction dY);
    GreenAlien(int x, int y, Direction dX, Direction dY, int leftL, int upL, int rightL, int downL, int xLimit, int yLimit);
    virtual ~GreenAlien();
private:
    virtual bool checkCollisions();
public slots:
    virtual void move();
};

#endif // GREENALIEN_H
