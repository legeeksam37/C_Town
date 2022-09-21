#include "Freewomencounter.h"
#include <QFont>


Freewomencounter::Freewomencounter(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //initialize the score to 0 at the beginig
    counter = 0;

    //We draw the score and tranforming into string
    setPlainText("Women saved: " + QString::number(counter));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Freewomencounter::increase()
{
    //on incrémente uniquement à chaque appel de la fonction
    counter++;
    //we update the text
    setPlainText("Women saved: " + QString::number(counter));

}

void Freewomencounter::increase(int i)
{
    counter = counter + i;
    setPlainText("Women saved: " + QString::number(counter));
}


int Freewomencounter::get()
{
    return counter;
}
