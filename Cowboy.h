#ifndef Cowboy_H
#define Cowboy_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsRectItem>
#include "Dame.h"

class Cowboy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    Cowboy(QGraphicsItem * parent =0);

    void keyPressEvent(QKeyEvent * event);
    void needHorse();
    int Increaserespect();
    int DecreaseRespecct();
    int getRespect();
    void gotHorse();
    void leaveHorse();
    bool getOwnHorse();
    void SetWalkedOnHedgehog();
    bool getWalkedOnHedgehog();
    void setVitesse();
    int getVitesse();
    void meetWomen();
    void saveWomen();
    void leaveWomen();
    int increaseNbreWomen();
    int getnbreWomen();
    int setnbreWomen();
    //int increaseWomen();

public slots:
    void spawn();
    void spawnDame();
    void spawnHedgehog();
    void spawnHorse();
    void spawnSnake();
signals:


 private:
    QMediaPlayer * bulletsound;
    int respect;
    bool ownHorse;
    bool WalkedOnHedgehog;
    int vitesse;
    bool collideWall;
    double X_Prev ;
    double Y_Prev;
    bool savedW;
    int nbreWomens;

};

#endif // Cowboy_H
