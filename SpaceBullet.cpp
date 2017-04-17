#include "SpaceBullet.h"
#include "Game.h"

extern Game* game;

SpaceBullet::SpaceBullet(QGraphicsItem* parent): Bullet(parent)
{
    // set graphics.
    setPic(QPixmap(":/images/bullet.png"));
    setPic(getPic().scaled(QSize(30,30), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

void SpaceBullet::move(){
    if( ((x() < (game->width() - 500) / 2) || x() > ((game->width() - 500) / 2) + 500) && y() > 0){
        if(y() > 0){
            setY(y() - 10);
        }
        else{
            delete this;
        }
    }
    else{
        if(y() > 55){
            setY(y() - 10);
        }
        else{
            delete this;
        }
    }
}
