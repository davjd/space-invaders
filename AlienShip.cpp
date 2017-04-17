#include "AlienShip.h"
#include <QDebug>
#include <QPixmap>
#include "Game.h"
#include <typeinfo>
#include "SpaceBullet.h"
#include "AlienBullet.h"

extern Game* game;

AlienShip::AlienShip(QGraphicsItem* parent): Alien(parent)
{
    // set graphics.
    setPic(QPixmap(":/images/AlienShip.png"));
    setHeight(40);
    setWidth(40);
    setPic(getPic().scaled(QSize(width(),height()), Qt::KeepAspectRatio));
    setPixmap(getPic());
    setX(0);
    setY(60);
    health_ = 100;
    timer_ = new QTimer(this);
    timer_->setSingleShot(true);
    rate = new QTimer(this);
    rate->setSingleShot(true);
    startTimer(15000);

}

AlienShip::~AlienShip(){
    delete timer_;
    delete rate;
}

void AlienShip::startTimer(int t){
    timer_->start(t);
    getTimer()->start(100);
}

int AlienShip::health(){
    return health_;
}

void AlienShip::updateHealth(int h){
    health_ = h;
}


bool AlienShip::checkCollisions()
{

    QList<QGraphicsItem *> collided = collidingItems();
    for(int i = 0; i < collided.size(); ++i){
        if(typeid((*collided[i])) == typeid(SpaceShip)){
            game->getBoard()->updateScore(game->getBoard()->score() - 10);
            delete this;
            return true;
        }
        else if(typeid((*collided[i])) == typeid(SpaceBullet)){
            (dynamic_cast<SpaceBullet*> (collided[i]))->getTimer()->stop();
            delete (dynamic_cast<SpaceBullet*> (collided[i]));
            game->getBoard()->updateScore(game->getBoard()->score() + 1);

            if(health() < 10){
                delete this;
                return true;
            }
            else{
                health_ -= 10;
            }

        }
    }
    return false;

}

void AlienShip::move(){
    if(game->getShip()->health() <= 0){
        getTimer()->stop();
    }
    if(checkCollisions()) return;
    if(timer_->isActive()){
        if(game->getShip()->x() < x()){
            setX(x() - 5);
        }
        else if(game->getShip()->x() > x()){
            setX(x() + 5);
        }
        else{
            if(!rate->isActive() && game->state() == game->State::ongoing){
                // create bullet and shoot.
                AlienBullet* b = new AlienBullet();
                b->setPos(x() + 5,y() + 13);
                scene()->addItem(b);
                rate->start(1000);
            }

        }
    }
    else{
        if(x() > -40){
            setX(x() - 10);
        }
        else{
            qDebug() << "object hidden.";
            getTimer()->stop();
        }
    }
}
