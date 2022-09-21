#include "Brigand.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <Game.h>
#include <QDebug>
#include <Cowboy.h>


extern Game * game;



int Brigand::Rand(int a, int b)
{
    int random;
    random = a+(int)((float)rand()*(b-a+1)/(RAND_MAX-1));
    return random;
}

Brigand::Brigand(QGraphicsItem * parent) : QObject(),  QGraphicsPixmapItem()
{
    //défini une position random entre 510 et 610
   int x = 1200;
   int y = Rand(510,610);


    setPos(x,y);

    //defini la taille du rectangle
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/img/joe-dalton(2).png"));

    //on créer le timer qui permet de connecter au slot et de pouvoir tirer
    QTimer * timer = new QTimer();
    //connect the timer to the slot
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     timer->start(50);

}

Brigand::~Brigand()
{

}

void Brigand::move()
{




    //on faire bouger l'ennemi
       setPos(x()-10, y());
       //si la'ennemi sort de la scene alors on al supprime pour libérer l'espcace mémoire
       if(pos().x() < 0){
          // game->health->decrease();
           game->counterBandits->increase();
           scene()->removeItem(this);
           delete this;
       }


        //if brigand has touched cowboy, the health of the cowboy decrease
       QList<QGraphicsItem *> colliding_cb = collidingItems();
        for(int i = 0, n = colliding_cb.size(); i<n ; i++){
            if(typeid(*(colliding_cb[i])) == typeid(Cowboy)){
                //decrease the health if the cowboy is not on the horse
               if(game->cowboy->getOwnHorse()==false){
                    game->health->decrease();
                    //else the brigand is killed
               }else if(game->cowboy->getOwnHorse()==true){
                    game->health->decrease();
                    game->cowboy->needHorse();
                    game->cowboy->leaveWomen();
                    game->cowboy->getnbreWomen();
                 /*  scene()->removeItem(this);
                   delete this;
                   return;*/
               }
            }




    }
}
