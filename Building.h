#ifndef BUILDING_H
#define BUILDING_H


#include "QGraphicsRectItem"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>



class Building : public QObject, public QGraphicsPixmapItem{
     Q_OBJECT
public :

    Building(QGraphicsItem * parent =0);
};


#endif // BUILDING_H
