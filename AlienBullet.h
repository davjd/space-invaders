#ifndef ALIENBULLET_H
#define ALIENBULLET_H

#include "Bullet.h"
#include <QGraphicsItem>
#include <QObject>

class AlienBullet: public Bullet{
    Q_OBJECT
public:
    AlienBullet(QGraphicsItem* parent = 0);
public slots:
    virtual void move();
    bool hasCollided();
};

#endif // ALIENBULLET_H
