#include <QFont>
#include "Freebrigands.h"

Freebrigands::Freebrigands(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //initialize the score to 0 at the beginig
    counter = 0;

    //We draw the score and tranforming into string
    setPlainText("Free bandits : " + QString::number(counter));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
#include "Freebrigands.h"


void Freebrigands::increase()
{
    //on incrémente uniquement à chaque appel de la fonction
    counter++;
    //we update the text
    setPlainText("Free bandits : " + QString::number(counter));

}


int Freebrigands::get()
{
    return counter;
}
