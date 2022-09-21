#ifndef WALL2_H
#define WALL2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Snake: public QObject , public QGraphicsPixmapItem{
     Q_OBJECT
    public :
     int Rand(int a, int b);
     Snake(QGraphicsItem * parent = 0);
 public slots:
     void onScene();
 };




#endif // WALL2_H
