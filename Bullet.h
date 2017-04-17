#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent = 0);
    QTimer* getTimer();
    QPixmap getPic();
    void setPic(QPixmap p);
private:
    QTimer* timer;
    QPixmap pic;
public slots:
    virtual void move();
};

#endif // BULLET_H
