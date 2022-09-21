#include <QApplication>
#include <QGraphicsScene>
#include "Cowboy.h"
#include "Game.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QDebug>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   game = new Game();
 // game->show();


    return a.exec();
}
