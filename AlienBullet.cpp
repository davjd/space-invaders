#include "AlienBullet.h"
#include "SpaceShip.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>

extern Game* game;
AlienBullet::AlienBullet(QGraphicsItem* parent): Bullet(parent)
{
    // set graphics.
    setPic(QPixmap(":/images/AlienBullet.png"));
    setPic(getPic().scaled(QSize(30,30), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

bool AlienBullet::hasCollided(){
    QList<QGraphicsItem *> collided = collidingItems();
    for(int i = 0; i < collided.size(); ++i){
        if(typeid((*collided[i])) == typeid(SpaceShip)){
            game->getBoard()->updateScore(game->getBoard()->score() - 10);
            (dynamic_cast<SpaceShip*> (collided[i]))->updateHealth(
                        (dynamic_cast<SpaceShip*> (collided[i]))->health() - 10);
            getTimer()->stop();
            delete this;
            return true;
        }
    }
    return false;
}

void AlienBullet::move(){
    if(game->getShip()->health() <= 0){
        game->lose();
        getTimer()->stop();
        delete this;
        return;
    }
    if(hasCollided()){
        qDebug() << "Collision occured";
        return;

    }
    else{
        if(y() < game->scene->height()){
            setY(y() + 10);
        }
        else{
            delete this;
        }
    }
}
