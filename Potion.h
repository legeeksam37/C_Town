#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Potion: public QObject , public QGraphicsPixmapItem{
     Q_OBJECT
    public :
     int Rand(int a, int b);
     Potion(QGraphicsItem * parent = 0);
 public slots:
     void onScene();
 };





#endif // HEDGEHOG_H
