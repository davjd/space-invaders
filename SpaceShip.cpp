#include "SpaceShip.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "SpaceBullet.h"
#include "Game.h"

extern Game* game;

SpaceShip::SpaceShip(QGraphicsItem *parent)
{
    // initialize the image.
    QPixmap ship(":/images/spaceShip.png");
    height = 80;
    width = 80;
    // resize the image.
    ship = ship.scaled(QSize(getWidth(),getHeight()), Qt::KeepAspectRatio);
    // set the image.
    setPixmap(ship);
    health_ = 100;


    timer = new QTimer();
    timer->setSingleShot(true);
}

bool SpaceShip::sceneEvent(QEvent *event)
{
    if(event->type()==QEvent::KeyPress) {
        pressedKeys += ((QKeyEvent*)event)->key();
        if(pressedKeys.contains(Qt::Key_Space) ){
            if(!timer->isActive()){
                SpaceBullet *b = new SpaceBullet();
                b->setPos(x() + 34,y() - 37);
                scene()->addItem(b);
                timer->start(600);
            }
        }

        if(pressedKeys.contains(Qt::Key_Left)){
            if(x() - 10 >= 0)
                setPos(x() - 10, y());
        }
        else if(pressedKeys.contains(Qt::Key_Right)){
            if(x() + 10 + getWidth() <= scene()->width())
                setPos(x() + 10, y());
        }
    }
    else if(event->type()==QEvent::KeyRelease)
    {

        if(((QKeyEvent*)event)->key() == Qt::Key_Space){
            if(pressedKeys.contains(Qt::Key_Left)){
                if(x() - 10 >= 0)
                    setPos(x() - 10, y());
            }
            else if(pressedKeys.contains(Qt::Key_Right)){
                if(x() + 10 + getWidth() <= scene()->width())
                    setPos(x() + 10, y());
            }
        }

        pressedKeys -= ((QKeyEvent*)event)->key();
    }


    return false;
}

int SpaceShip::getWidth()
{
    return width;
}

int SpaceShip::getHeight()
{
    return height;
}

void SpaceShip::updateHealth(int h){
    health_ = h;
}

int SpaceShip::health(){
    return health_;
}
