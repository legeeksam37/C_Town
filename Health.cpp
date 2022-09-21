#include "Health.h"
#include <QFont>
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent)
{
    health = 200;


    if(health==0){
        for (size_t i = 0, n = scene()->items().size(); i < n; i++){
                scene()->items()[i]->setEnabled(false);
            }
        // pop up semi transparent panel
            //drawPanel(0,0,1024,768,Qt::black,0.65);

            // draw panel
           // drawPanel(312,184,400,400,Qt::lightGray,0.75);
    }

    //We draw the health and tranforming into string
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health));

}

int Health::getHealth()
{
    return health;
}

void Health::increase()
{
    health = health+10;
    setPlainText("Health: " + QString::number(health));
}

