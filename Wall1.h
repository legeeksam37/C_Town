#ifndef WALL1_H
#define WALL1_H

#include "QGraphicsRectItem"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>



class Wall1 : public QObject, public QGraphicsPixmapItem{
     Q_OBJECT
public :

    Wall1(QGraphicsItem * parent =0);

public slots:

private:



};




#endif // WALL1_H
