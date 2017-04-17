#ifndef ALIENSHIP_H
#define ALIENSHIP_H

#include "Alien.h"
#include <QObject>

class AlienShip: public Alien{
    Q_OBJECT
public:
    AlienShip(QGraphicsItem* parent = 0);
    virtual ~AlienShip();
    QTimer* timer();
    int health();
    void updateHealth(int h);

private:
    virtual bool checkCollisions();
    void startTimer(int t);
    int health_;

    QTimer* timer_;
    QTimer* rate;
public slots:
    virtual void move();
};

#endif // ALIENSHIP_H
