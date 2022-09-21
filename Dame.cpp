#include "Dame.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Brigand.h"

#include "Score.h"
#include "Game.h"
#include "Cowboy.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//QGraphicsPixmapItem





extern Game * game;
//we first define an random number for the women position
int Dame::Rand(int a, int b){
    int random;
    random = a+(int)((float)rand()*(b-a+1)/(RAND_MAX-1));
    return random;
}



Dame::Dame(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/img/Dame.png"));
    //génère un nombre alétoire pour la position
    int xPosition = Rand(400,750);


    //défini la position
    setPos(xPosition,y()+308);

    //on créer le timer qui permet de connecter au slot et de pouvoir tirer
    QTimer * timer = new QTimer();
    //connect the timer to the slot
     connect(timer,SIGNAL(timeout()),this,SLOT(Appears()));
     timer->start(50);
 }




void Dame::Appears()
{
    //if women has touched brigand, she's free from the jail

   QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if(typeid(*(colliding_items[i]))== typeid(Cowboy)){
            //increase the score
            game->score->increase();
            //game->counter->increase();
            //remove the women
            if(game->cowboy->getOwnHorse()==true){
            game->cowboy->meetWomen();
            game->cowboy->saveWomen();
            game->cowboy->increaseNbreWomen();
            scene()->removeItem(this);

            //delete the women to free memory
            delete this;
            return;
        }


        }
    }


    /*on faire bouger la balle
       setPos(x()+50, y());
       //si la balle sort de la scene alors on al supprime pour libérer l'espcace mémoire
       if(pos().x() > 800){
           scene()->removeItem(this);
           delete this;
       }*/
}
