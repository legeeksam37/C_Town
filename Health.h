#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>


class Health: public QGraphicsTextItem{

  public:

    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
    void increase();

private:
    int health;

};






#endif // HEALTH_H
