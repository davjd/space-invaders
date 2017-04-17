#include "Scoreboard.h"
#include "Game.h"
#include <QDebug>

extern Game* game;


ScoreBoard::ScoreBoard()
{
    score_ = 0;

}

ScoreBoard::ScoreBoard(int s)
{
    setRect(0,0,100,100);
    score_ = s;

}

void ScoreBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *){
    if(game->state() == game->State::ongoing){
        painter->drawRect((game->width() - 500) / 2,0, 500,50);
        painter->drawText(
                    QRect((game->width() - 500) / 2, 0,500,50),
                    Qt::AlignCenter, "Score: " + QString::number(score())
                    );
        painter->drawText(
                    QRect((game->width() - 500) / 2, 12,500,50),
                    Qt::AlignCenter, "Health: "
                    + QString::number(game->getShip()->health()));
    }
    else{
        QString state;
        if(game->state() == game->State::won){
            state = "won";
        }
        else{
            state = "lost";
        }

        painter->drawRect((game->width() - 500) / 2,0, 500,50);
        painter->drawText(
                    QRect((game->width() - 500) / 2, 0,500,50),
                    Qt::AlignCenter, "You have"
                    + state
                    + " with a score of"
                    + QString::number(score())
                    + "\n and health of "
                    + QString::number(game->getShip()->health()));
    }

}



void ScoreBoard::updateScore(int s){
    score_ = s;
    update();
    game->viewport()->repaint();
}

int ScoreBoard::score(){
    return score_;
}
