#include "Horse.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern Game * game;

int Horse::Rand(int a, int b)
{
    int random;
    random = a+(int)((float)rand()*(b-a+1)/(RAND_MAX-1));
    return random;
}

Horse::Horse(QGraphicsItem *parent)
{
    //défini une position random
    setPos(0,500);

    //defini la taille du rectangle
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/img/horse.png"));

    //on créer le timer qui permet de connecter au slot et de pouvoir tirer
    QTimer * timerHorse = new QTimer();
    //connect the timer to the slot
     connect(timerHorse,SIGNAL(timeout()),this,SLOT(onScene()));

     timerHorse->start(50);
     //game->cowboy->SetownHorse(false);
}

void Horse::onScene()
{
        //if brigand has touched cowboy, the health of the cowboy decrease
       QList<QGraphicsItem *> colliding_cb = collidingItems();
        for(int i = 0, n = colliding_cb.size(); i<n ; i++){
            if(typeid(*(colliding_cb[i]))== typeid(Cowboy)){
                //decrease the health if the cowboy is not on the horse
                   game->cowboy->gotHorse();
                   game->cowboy->needHorse();
                   game->cowboy->setVitesse();
                   //game->cowboy->;
                    //else the brigand is killed
                    if(game->cowboy->getOwnHorse()==true){
                   scene()->removeItem(this);
                   delete this;
                   return;
               }
            }

    }



        //on faire bouger le cheval
           setPos(x()+30, y());
           //if the horse gozs out of the scene, we free the memory
           if(pos().x() >1200){
               //scene()->removeItem(this);
               delete this;
               return;
           }
}
