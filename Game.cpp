#include "Game.h"
#include "Bullet.h"
#include "Scoreboard.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include "AlienShip.h"


Game::Game(): QGraphicsView(){
    state_ = ongoing;
    // number of spaces that will not be
    // used by the group of invader sprites.
    const int FREE_SPACE = 15;
    const int rows = 3;
    count_ = 0;

    // set properties of window.
    setFixedSize(800,600); // scene size.

    // create the scene.
    scene = new QGraphicsScene(this);
    // set the scene's bounding rect to rect of mainwindow
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    ship = new SpaceShip();
    ship->setPos((scene->width() / 2) - (ship->getWidth() / 2), scene->height() - (ship->getHeight() * 1));

    // make ship focusable so it listens to key listeners.
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    // now make the ship actually focused.
    ship->setFocus();

    scene->addItem(ship);
    scoreB = new ScoreBoard();

    // add aliens to screen.
    aliens_ = new QVector< QVector<GreenAlien*>* >(); // YEEEET

    // calculate measurements for aliens in screen.
    // total number of avaliables spaces for aliens.
    int len = scene->width() / 40;
    int real_len = len - FREE_SPACE;
    int aliens_width = real_len * 40;
    int x_spacing =   (scene->width() - aliens_width) / 2;
    int  x_start = x_spacing;
    int x_end = aliens_width + x_spacing;

    qDebug() << "l: " << scene->width()  << "start: " << x_start << ", end: " << x_end;
    for(int y = 0; y < rows; ++y){
        aliens_->push_back(new QVector<GreenAlien*>());
        for(int x = 0; x < real_len; ++x){
            aliens_->at(y)->push_back(new GreenAlien((x * 40) + x_start, (45 * y) + 100));

            aliens_->at(y)->at(x)->setLeftLim(x * aliens_->at(y)->at(x)->width());
            aliens_->at(y)->at(x)->setRightLim(((x + (FREE_SPACE + 1)) * aliens_->at(y)->at(x)->width()));

            aliens_->at(y)->at(x)->setUpLim(800);
            aliens_->at(y)->at(x)->setDownLim(500);

            aliens_->at(y)->at(x)->setYDirection(Alien::Direction::down);
            aliens_->at(y)->at(x)->setXDirection(Alien::Direction::left);
            aliens_->at(y)->at(x)->start(100);
            scene->addItem(aliens_->at(y)->at(x));
            ++count_;
        }
    }

    AlienShip* alien = new AlienShip();
    scene->addItem(alien);
    scene->addItem(scoreB);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

ScoreBoard* Game::getBoard(){
    return scoreB;
}

SpaceShip* Game::getShip(){
    return ship;
}

int Game::count(){
    return count_;
}

QVector<GreenAlien*>* Game::aliens(int i){
    return aliens_->at(i);
}

void Game::updateCount(int c){
    count_ = c;
}

Game::State Game::state(){
    return state_;
}

void Game::delAlien(GreenAlien *alien){
    for(int y = 0, yEnd = aliens_ ->size(); y < yEnd; ++y){
        for(int x = 0, xEnd = aliens_->at(y)->size(); x < xEnd; ++x){
            if(aliens_->at(y)->at(x) == alien){
                aliens_->at(y)->remove(x);
                return;
            }
        }
    }
}

void Game::lose(){
    over(lost);
}

void Game::win(){
    over(won);
}

void Game::over(Game::State newState){
    if(state() != ongoing){
        qDebug() << "game alread paused.";
        return;
    }
    else{
        state_ = newState;
    }

    qDebug() << "size: " << aliens_->at(0)->size();

    for(int y = 0, yEnd = aliens_->at(y)->size(); y < yEnd; ++y){
        for(int x = 0, xEnd = aliens_->at(y)->size(); x < xEnd; ++x){
            aliens_->at(y)->at(x)->getTimer()->stop();
            qDebug() << "timer stopped.";
        }
    }
    if(state() == won){
        qDebug() << "Game is over, you won.";
    }
    else{
        qDebug() << "Game is over, you lost.";
    }
}
