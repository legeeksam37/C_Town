#include "Snake.h"
#include "Game.h"
#include "Cowboy.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game;


int Snake::Rand(int a, int b)
{
    int random;
    random = a+(int)((float)rand()*(b-a+1)/(RAND_MAX-1));
    return random;
}

Snake::Snake(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/img/snake.png"));
    //generate random number for position
    int XPosition = Rand(1,1200);
    int Yposition = Rand(510,740);

    //define the position
    setPos(XPosition,Yposition);

    //create timer that allows us to show the snake on the scene each ... seconds
    QTimer * timer = new QTimer();
    //connect the timer to the slot
     connect(timer,SIGNAL(timeout()),this,SLOT(onScene()));
     timer->start(50);
}

void Snake::onScene()
{

    //if the Snake has touched the potion, the health decrease
   QList<QGraphicsItem *> colliding_Hed = collidingItems();
    for(int i = 0, n = colliding_Hed.size(); i<n ; i++){
        if(typeid(*(colliding_Hed[i]))== typeid(Cowboy)){
            //increase the score if the cowboy is not on a horse
            if(game->cowboy->getOwnHorse()==false && game->health->getHealth()<100){
                 game->health->decrease();
            }
            //remove the snake
            scene()->removeItem(this);
            //delete the snake to free memory
            delete this;

            return;
        }
}

}
