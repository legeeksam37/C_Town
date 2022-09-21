#include "Building.h"


Building::Building(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/img/sherifHouse.png"));
    setPos(870,630);
}
