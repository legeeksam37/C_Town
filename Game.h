  #ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include "Cowboy.h"
#include <QGraphicsView>
#include <QWidget>
#include "Score.h"
#include "Health.h"
#include "Dame.h"
#include "Horse.h"
#include "Potion.h"
#include "Freewomencounter.h"
#include "Freebrigands.h"
#include "Wall1.h"
#include "Building.h"
#include"Snake.h"


class Game: public QGraphicsView{

public:

    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Cowboy * cowboy;
    Score * score;
    Health * health;
    Dame * dame;
    Potion * hed;
    Horse * horse;
   Freewomencounter * counter;
   Freebrigands * counterBandits;
   Wall1 * wall;
   Building * jail;
   Snake * snake;
   Building * sherif;
   void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
   int getCeilling();

private:

   int ceilling;
   int appearswomen;
   int appearsBrigands;

public slots:




};
#endif // GAME_H

