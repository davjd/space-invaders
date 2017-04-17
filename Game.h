#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QVector>
#include "GreenAlien.h"
#include "Scoreboard.h"
#include "SpaceShip.h"

class Game: public QGraphicsView{
public:
    Game();

    // member fields.
    QGraphicsScene* scene;
    ScoreBoard* getBoard();
    SpaceShip* getShip();
    int count();
    void updateCount(int c);
    void delAlien(GreenAlien *alien);
    QVector<GreenAlien*>* aliens(int i);
    enum State{
        ongoing, lost, won
    };

    State state();
    void over(State newState);
    void lose();
    void win();


private:
    QVector< QVector<GreenAlien*>* > *aliens_;
    ScoreBoard* scoreB;
    SpaceShip* ship;
    State state_;
    int count_;
};

#endif // GAME_H
