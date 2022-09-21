#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //initialize the score to 0 at the beginig
    score = 0;

    //We draw the score and tranforming into string
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase()
{
    //on incrémente uniquement à chaque appel de la fonction
    score = score+1;
    //we update the text
    setPlainText("Score: " + QString::number(score));

}


int Score::getScore()
{
    return score;
}
