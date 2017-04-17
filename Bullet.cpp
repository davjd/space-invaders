#include "Bullet.h"
#include <QDebug>
#include "Game.h"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
}

QTimer* Bullet::getTimer(){
    return timer;
}

QPixmap Bullet::getPic(){
    return pic;
}
void Bullet::setPic(QPixmap p){
    pic = p;
}
