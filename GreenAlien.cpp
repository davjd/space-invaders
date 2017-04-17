#include "GreenAlien.h"
#include <QTimer>
#include <QDebug>
#include <typeinfo>
#include "SpaceShip.h"
#include "SpaceBullet.h"
#include "Game.h"
#include <QObject>
extern Game* game;

GreenAlien::GreenAlien(QGraphicsItem* parent) : Alien(parent)
{
    // set graphics.
    setPic(QPixmap(":/images/greenAlien.png"));
    setPic(getPic().scaled(QSize(width(),height()), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

GreenAlien::GreenAlien(int x, int y) : Alien(x, y)
{
    // set graphics.
    setPic(QPixmap(":/images/greenAlien.png"));
    setPic(getPic().scaled(QSize(width(),height()), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

GreenAlien::GreenAlien(int x, int y, Alien::Direction dX, Alien::Direction dY): Alien(x, y, dX, dY)
{
    // set graphics.
    setPic(QPixmap(":/images/greenAlien.png"));
    setPic(getPic().scaled(QSize(width(),height()), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

GreenAlien::GreenAlien(int x, int y, Alien::Direction dX, Alien::Direction dY, int leftL, int upL, int rightL, int downL, int xLimit, int yLimit): Alien(x, y, dX, dY, leftL, upL, rightL, downL, xLimit, yLimit)
{
    // set graphics.
    setPic(QPixmap(":/images/greenAlien.png"));
    setPic(getPic().scaled(QSize(width(),height()), Qt::KeepAspectRatio));
    setPixmap(getPic());
}

GreenAlien::~GreenAlien(){
    game->delAlien(this);
}

bool GreenAlien::checkCollisions(){
    QList<QGraphicsItem *> collided = collidingItems();
    for(int i = 0; i < collided.size(); ++i){
        if(typeid((*collided[i])) == typeid(SpaceShip)){
            game->getBoard()->updateScore(game->getBoard()->score() - 1);
            (dynamic_cast<SpaceShip*> (collided[i]))->updateHealth(
                        (dynamic_cast<SpaceShip*> (collided[i]))->health() - 10);
            game->updateCount(game->count() - 1);
            delete this;
            if(game->count() == 0){
                game->win();
            }
            return true;
        }
        else if(typeid((*collided[i])) == typeid(SpaceBullet)){
            (dynamic_cast<SpaceBullet*> (collided[i]))->getTimer()->stop();
            delete (dynamic_cast<SpaceBullet*> (collided[i]));
            game->getBoard()->updateScore(game->getBoard()->score() + 1);
            game->updateCount(game->count() - 1);
            delete this;
            if(game->count() == 0){
                qDebug() << "count is zero.";
                game->win();
            }
            return true;
        }


    }
    return false;
}


void GreenAlien::move(){
    if(checkCollisions() || (game->State::ongoing != game->state())) return;
    if(isGoingLeft()){
        // check if there is more room
        // to continue moving left.
        if(x() > getXLim()){
            setX(x() - 5);
        }
        else{
            // if there is no more space:
            // change direction and xLimit, move down, and increase speed.
            setXDirection(right);
            setXLim(getRightLim());
            if(y() < getYLim()){
                setY(y() + 20);
                //setRate(getRate() - 1);
            }
            else{
                // if yLim is reached,
                // game is over.
                qDebug() << "Game is over.";
            }

        }
    }
    else{
        // check if there is more room
        // to continue moving right.
        if(x() + 40 < getXLim()){
            setX(x() + 5);
        }
        else{
            // if there is no more space:
            // change direction and xLimit, move down, and increase speed.
            setXDirection(left);
            setXLim(getLeftLim());
            if(y() < getYLim()){
                setY(y() + 20);
                //setRate(getRate() - 1);
            }
            else{

                // if yLim is reached,
                // game is over.
                qDebug() << "Game is over. y: " << y()  << "ylim: " << getYLim();
                game->lose();
            }

        }
    }
}
