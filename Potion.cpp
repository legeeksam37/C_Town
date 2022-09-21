#include "Potion.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include "Cowboy.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern Game * game;
//nombre alétoire pour la position de l'Herisson et la vitesse en moins
int Potion::Rand(int a, int b)
{
    int random;
    random = a+(int)((float)rand()*(b-a+1)/(RAND_MAX-1));
    return random;
}

Potion::Potion(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/img/HealthPos.png"));
    //génère un nombre alétoire pour la position
    int XPosition = Rand(700,1200);
    int Yposition = Rand(510,610);


    //défini la position
    setPos(XPosition,Yposition);

    //on créer le timer qui permet de connecter au slot et de pouvoir tirer
    QTimer * timer = new QTimer();
    //connect the timer to the slot
     connect(timer,SIGNAL(timeout()),this,SLOT(onScene()));
     timer->start(50);
}

void Potion::onScene()
{
    //if the hedgehog has touched the potion, the health decrease
   QList<QGraphicsItem *> colliding_Hed = collidingItems();
    for(int i = 0, n = colliding_Hed.size(); i<n ; i++){
        if(typeid(*(colliding_Hed[i]))== typeid(Cowboy)){
            //increase the score if the cowboy is not on a horse
            if(game->health->getHealth()<100){
                 game->health->increase();
            }
            //remove the hedgehog
            scene()->removeItem(this);
            //delete the hedgehog to free memory
            delete this;

            return;
        }
}
}
