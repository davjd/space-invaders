#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QLabel>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class ScoreBoard: public QGraphicsRectItem
{
public:
    ScoreBoard();
    ScoreBoard(int s);
    void updateScore(int s);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *);
    int score();
private:
    int score_;

};

#endif // SCOREBOARD_H
