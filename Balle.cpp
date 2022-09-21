#include "Balle.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Brigand.h"
#include <QDebug>
#include "Score.h"
#include "Game.h"

extern Game * game;

Balle::Balle(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem()
{
    //defini la taille du rectangle
    setPixmap(QPixmap(":/img/laser_bullet.png"));

    //on créer le timer qui permet de connecter au slot et de pouvoir tirer
    QTimer * timer = new QTimer();
    //connect the timer to the slot
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     timer->start(50);
 }

void Balle::move()
{
    //if bullet has touched brigand, we destroy both
   QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if(typeid(*(colliding_items[i]))== typeid(Brigand)){
            //increase the score
            game->score->increase();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;

            return;
        }
    }


    //on faire bouger la balle
       setPos(x()+50, y());
       //si la balle sort de la scene alors on al supprime pour libérer l'espcace mémoire
       if(pos().x() > 1200){
           scene()->removeItem(this);
           delete this;
       }
}
