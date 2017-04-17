#include "Alien.h"
#include <QTimer>
#include <QDebug>
#include "Game.h"
#include <QObject>

extern Game* game;


Alien::Alien(QGraphicsItem* parent)
{

    w_ = 40;
    h_ = 40;

    // set default directions.
    xDir = left;
    yDir = up;

    // set default limits.
    leftLim = 0;
    rightLim = 0;
    upLim = 0;
    downLim = 0;
    xLim = leftLim;
    yLim = upLim;

    // timer:
    moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this, SLOT(move()));
}

Alien::Alien(int x, int y)
{

    w_ = 40;
    h_ = 40;

    // set coordinates:
    setPos(x,y);

    // set default directions.
    xDir = left;
    yDir = down;

    // set default limits.
    leftLim = 0;
    rightLim = 0;
    upLim = 0;
    downLim = 0;
    xLim = leftLim;
    yLim = downLim;

    // timer:
    moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this, SLOT(move()));
}

Alien::Alien(int x, int y, Alien::Direction dX, Alien::Direction dY)
{
    w_ = 40;
    h_ = 40;

    // set field.
    setPos(x,y); // coordinates.
    xDir = dX; // x-axis direction.
    yDir = dY; // y-axis direction.

    // set default limits.
    leftLim = 0;
    rightLim = 0;
    upLim = 0;
    downLim = 0;
    xLim = leftLim;
    yLim = upLim;

    // timer:
    moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this, SLOT(move()));
}

Alien::Alien(int x, int y, Alien::Direction dX, Alien::Direction dY, int leftL, int upL, int rightL, int downL, int xLimit, int yLimit)
{
    w_ = 40;
    h_ = 40;

    // set field.
    setPos(x,y); // coordinates.
    xDir = dX; // x-axis direction.
    yDir = dY; // y-axis direction.

    // set default limits.
    leftLim = leftL;
    rightLim = rightL;
    upLim = upL;
    downLim = downL;
    xLim = xLimit;
    yLim = yLimit;

    // timer:
    moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this, SLOT(move()));
}

Alien::~Alien(){
    delete moveTimer;
}

bool Alien::isGoingLeft()
{
    return (xDir == left);
}

bool Alien::isGoingRight(){
    return (xDir == right);
}

bool Alien::isGoingUp(){
    return (yDir == up);
}

bool Alien::isGoingDown(){
    return (yDir == down);
}

int Alien::getXLim()
{
    return xLim;
}

int Alien::getYLim()
{
    return yLim;
}

int Alien::getRate(){
    return moveTimer->interval();
}

void Alien::setXLim(int x){
    xLim = x;
}

void Alien::setYLim(int y){
    yLim = y;
}


void Alien::setLeftLim(int l){
    leftLim = l;
}

void Alien::setRightLim(int l){
    rightLim = l;
}

void Alien::setUpLim(int l){
    upLim = l;
}

void Alien::setDownLim(int l){
    downLim = l;
}

void Alien::setXDirection(Alien::Direction d){
    xDir = d;
    xLim = (xDir == Alien::Direction::left) ? leftLim : rightLim;
}

void Alien::setYDirection(Alien::Direction d){
    yDir = d;
    yLim = (yDir == Alien::Direction::down) ? downLim : upLim;
}

void Alien::setRate(int r){
    moveTimer->setInterval(r);
}

void Alien::start(int t){
    moveTimer->start(t);
}

int Alien::getLeftLim(){
    return leftLim;
}
int Alien::getRightLim(){
    return rightLim;
}
int Alien::getUpLim(){
    return upLim;
}
int Alien::getDownLim(){
    return downLim;
}

int Alien::width(){
    return w_;
}

int Alien::height(){
    return h_;
}
void Alien::setWidth(int w){
    w_ = w;
}
void Alien::setHeight(int h){
    h_ = h;
}

QPixmap Alien::getPic(){
    return pic;
}
void Alien::setPic(QPixmap p){
    pic = p;
}

QTimer* Alien::getTimer(){
    return moveTimer;
}

bool Alien::checkCollisions(){
//    QList<QGraphicsItem *> collided = collidingItems();
//    for(int i = 0; i < collided.size(); ++i){
//        if(typeid((*collided[i])) == typeid(SpaceShip)){
//            game->getBoard()->updateScore(game->getBoard()->score() - 1);
//            delete this;
//            return true;
//        }
//        else if(typeid((*collided[i])) == typeid(Bullet)){
//            (dynamic_cast<Bullet*> (collided[i]))->getTimer()->stop();
//            delete (dynamic_cast<Bullet*> (collided[i]));
//            game->getBoard()->updateScore(game->getBoard()->score() + 1);
//            delete this;
//            return true;
//        }
//    }
    return false;
}


void Alien::move(){
//    if(checkCollisions()) return;
//    if(isGoingLeft()){
//        // check if there is more room
//        // to continue moving left.
//        if(x() > getXLim()){
//            setX(x() - 5);
//        }
//        else{
//            // if there is no more space:
//            // change direction and xLimit, move down, and increase speed.
//            setXDirection(right);
//            setXLim(rightLim);
//            if(y() < yLim){
//                setY(y() + 20);
//                //setRate(getRate() - 1);
//            }
//            else{
//                // if yLim is reached,
//                // game is over.
//                qDebug() << "Game is over.";
//            }

//        }
//    }
//    else{
//        // check if there is more room
//        // to continue moving right.
//        if(x() + 40 < getXLim()){
//            setX(x() + 5);
//        }
//        else{
//            // if there is no more space:
//            // change direction and xLimit, move down, and increase speed.
//            setXDirection(left);
//            setXLim(leftLim);
//            if(y() < yLim){
//                setY(y() + 20);
//                //setRate(getRate() - 1);
//            }
//            else{

//                // if yLim is reached,
//                // game is over.
//                qDebug() << "Game is over. y: " << y()  << "ylim: " << yLim;
//            }

//        }
//    }
}
