#include "Game.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Cowboy.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QFont>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QImage>
#include <QString>


Game::Game(QWidget *parent)
{




//variables
    ceilling = 400;


    //here I creat the elements that will appears on the scene



    //create a scene

    QGraphicsScene * scene = new QGraphicsScene();
    //size of the scene
    scene->setSceneRect(0,0,1200,800);
    //Background image

    scene->setBackgroundBrush(QBrush(QImage(":/img/background.png")));


    //Create an item that we put into the scene

    cowboy = new Cowboy();
  // cowboy->setRect(0,0,100,100);
    QPixmap image(":/img/cowboy.png");
    QPixmap imageHorse(":/img/horse.png");
    //we add the item to the scene
    cowboy->setPixmap(image);

    if(cowboy->getOwnHorse()==true){
         cowboy->setPixmap(imageHorse);
    }

    scene->addItem(cowboy);



    //make the item focusable

    cowboy->setFlag(QGraphicsItem::ItemIsFocusable);
    cowboy->setFocus();

    //we add the view

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //show the view


    view->setFixedSize(1200,800);
    view->setWindowTitle("The C++ Town");
    view->show();

    cowboy->setPos(550,500);

    //create the score
    score = new Score();
    score->setPos(score->x()+400 , score->y());
    scene->addItem(score);

    //create the health
     health = new Health();
     health->setPos(health->x() , health->y()+25);
     scene->addItem(health);

     // add the women saved counter
     counter = new Freewomencounter;
     counter->setPos(counter->x(), counter->y()+50);
     scene->addItem(counter);

     // add the free bandits saved counter
     counterBandits = new Freebrigands;
     counterBandits->setPos(counterBandits->x(), counterBandits->y()+75);
     scene->addItem(counterBandits);

     //put the wall on the scene
     wall = new Wall1();
     scene->addItem(wall);

     //put the sherif office on the scene
     sherif = new Building();
     scene->addItem(sherif);







    //Spawn brigands
     QTimer * timerBrigand = new QTimer();
     QObject ::connect(timerBrigand,SIGNAL(timeout()),cowboy,SLOT(spawn()));
    timerBrigand->start(4000);

    //spawn the women
    QTimer * timerDame = new QTimer();
    QObject ::connect(timerDame,SIGNAL(timeout()),cowboy,SLOT(spawnDame()));
    dame = new Dame();
    if(cowboy->getOwnHorse()==true){
    timerDame->start(7000);
    }
    else if(cowboy->getOwnHorse()==false){
        timerDame->start(40000);
    }

    //spawn the hedgehog
    QTimer * timerHedgehog = new QTimer();
    QObject ::connect(timerHedgehog,SIGNAL(timeout()),cowboy,SLOT(spawnHedgehog()));
    hed = new Potion();
    timerHedgehog->start(12000);

    QTimer * timerSnake = new QTimer();
    QObject ::connect(timerSnake,SIGNAL(timeout()),cowboy,SLOT(spawnSnake()));
    hed = new Potion();
    timerSnake->start(9000);


//create the horse only if the cowboy doesn't have one yet

    QTimer * timerHorse = new QTimer();
    QObject ::connect(timerHorse,SIGNAL(timeout()),cowboy,SLOT(spawnHorse()));
    horse = new Horse();
    timerHorse->start(4000);



    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/bg.mp3"));
    music->play();


}



int Game::getCeilling()
{
    return ceilling;
}
