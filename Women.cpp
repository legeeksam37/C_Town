#include "Women.h"
#include "Cowboy.h"
#include <QKeyEvent>
#include "Balle.h"
#include <QGraphicsScene>
#include <QDebug>
#include "Brigand.h"
#include <QMediaPlayer>


Women::Women(QGraphicsItem *parent)
{
    //image of the women
    setPixmap(QPixmap(":/img/women.jpg"));
}

Women::~Women()
{

}


void Women::appears()
{

}
