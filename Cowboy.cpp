#include "Cowboy.h"
#include <QKeyEvent>
#include "Balle.h"
#include <QGraphicsScene>
#include <QDebug>
#include "Brigand.h"
#include <QMediaPlayer>
#include "Dame.h"
#include "Potion.h"
#include "Horse.h"
#include "Score.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <QString>
#include "Game.h"
#include "Wall1.h"
#include <QList>
#include "Snake.h"
#include "Building.h"


// if( pos.y() > 400 && pos.y() < 500


extern Game * game;

Cowboy::Cowboy(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    ownHorse = false;
    savedW == false;
    vitesse = 15;







   /* if(ownHorse == false){
        vitesse = 10;
   }else if(ownHorse == true){
        vitesse = 50;

    }*/

        // setPixmap(QPixmap(url));



      //  setPixmap(QPixmap(":/img/horse.png"));


    bulletsound= new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/bullet.mp3"));


}

void Cowboy::keyPressEvent(QKeyEvent *event)
{

        X_Prev = pos().x();
        Y_Prev = pos().y();







    //&& !collidesWithItem(Wall1)

    if(event->key() == Qt::Key_Left){
        //si la position ne dépasse pas le bord
        if(pos().x()>0)
         setPos(x()-vitesse,y());
        }


    if(event->key() == Qt::Key_Right){
        //si la position plus la taille du carée ne dépasse pas la largeur de la fenêtre
        if(pos().x()+100 < 1200)
        setPos(x()+vitesse,y());
    } if(event->key() == Qt::Key_Up /*&& !(typeid(*(colliding_cb[i]))== typeid(Wall1))*/ ){
            if(pos().y()> 0 && pos().y()>game->getCeilling())
             setPos(x(),y()-vitesse);
    } if(event->key() == Qt::Key_Down){
        if(pos().y()+100 < 800)
        setPos(x(),y()+vitesse);
    } if(event->key() == Qt::Key_Space){
        //on créer une balle quand on appuie sur espace
        Balle * balle = new Balle();
        //position de la balle sur la scene
        if(ownHorse==false){
           balle->setPos(x()+50,y()+42);
            scene()->addItem(balle);
        }else if(ownHorse==true){
             balle->setPos(x()+100,y()+52);
              scene()->addItem(balle);

        }
       // balle->setPos(x()+50,y()+42);
       // scene()->addItem(balle);

       // Play the sound of the balle
        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }else if(bulletsound->state()==QMediaPlayer::StoppedState)
            bulletsound->play();
    }



    //if the cowboy collides with a wall, he doesn' move anymore
    QList<QGraphicsItem *> colliding_cb = collidingItems();
        for(int i = 0, n = colliding_cb.size(); i<n ; i++){
            if(typeid(Wall1)==typeid(*(colliding_cb[i]))){
                    setPos(X_Prev,Y_Prev);
                    return;
            }
        }

         //if the cowboy collides with sherif office, women is saved
        QList<QGraphicsItem *> colliding_office = collidingItems();
            for(int i = 0, n = colliding_office.size(); i<n ; i++){

            if(typeid(Building)==typeid(*(colliding_office[i]))){
                        //increase the number of women saved if he cpatured women

                        //The women leaves the horse
                        if(ownHorse == true){
                            game->cowboy->needHorse();
                        }
                        if(savedW== true){
                        game->counter->increase(game->cowboy->setnbreWomen());
                        savedW = false;
                        }

                        setPos(X_Prev,Y_Prev);
                        getnbreWomen();
                        return;

                }
            }
}




void Cowboy::needHorse(){
    setPixmap(QPixmap(":/img/cowboyHorse.png"));
    //setProperty(ownHorse,true);
}

int Cowboy::Increaserespect()
{
    return this->respect++;
}

int Cowboy::DecreaseRespecct()
{
    return this->respect--;
}

int Cowboy::getRespect()
{
    return this->respect;
}

void Cowboy::gotHorse()
{
      ownHorse = true;
}


void Cowboy::leaveHorse(){
    ownHorse = false;
}

bool Cowboy::getOwnHorse()
{
    return this->ownHorse;
}

void Cowboy::SetWalkedOnHedgehog()
{
    WalkedOnHedgehog = true;
}

bool Cowboy::getWalkedOnHedgehog()
{
    return this->WalkedOnHedgehog;
}

void Cowboy::setVitesse()
{
    vitesse = 50;
}

int Cowboy::getVitesse()
{
    return this->vitesse;
}

void Cowboy::meetWomen()
{
    setPixmap(QPixmap(":/img/cowboyHorseWomen.png"));
}

void Cowboy::saveWomen()
{
    savedW = true;
}

void Cowboy::leaveWomen()
{
    savedW = false;
}

int Cowboy::increaseNbreWomen(){
     nbreWomens++;
}

int Cowboy::getnbreWomen()
{
    nbreWomens = 0;
}

int Cowboy::setnbreWomen()
{
    return nbreWomens;
}

/*int Cowboy::increaseWomen()
{
     nbreWomens++;
}*/

void Cowboy::spawn()
{
    //on créer un brigand
    Brigand * bg = new Brigand();
    scene()->addItem(bg);

}

void Cowboy::spawnDame()
{
        Dame * dame = new Dame();
        scene()->addItem(dame);
}

void Cowboy::spawnHedgehog()
{
    //on créer un hérisson
   Potion * hed = new Potion();
     scene()->addItem(hed);
}

void Cowboy::spawnHorse()
{

     if(ownHorse==false){
    // on créer le cheval
    Horse * horse = new Horse();
    scene()->addItem(horse);
}


}

void Cowboy::spawnSnake()
{
    //add th snake
    Snake * snake;
    snake = new Snake();
    scene()->addItem(snake);
}
