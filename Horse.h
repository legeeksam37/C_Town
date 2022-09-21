#ifndef HORSE_H
#define HORSE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Horse :  public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
   public :
    int Rand(int a, int b);
    Horse(QGraphicsItem * parent = 0);
public slots:
    void onScene();
};



#endif // HORSE_H
