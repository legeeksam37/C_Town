#include "Wall1.h"
#include "Game.h"
#include <QBrush>
#include <QImage>

extern Game * game;

Wall1::Wall1(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/img/stone-wall-texture.jpg"));
    setPos(0,530);

}

