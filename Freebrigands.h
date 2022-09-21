#ifndef FREEBRIGANDS_H
#define FREEBRIGANDS_H
#include <QGraphicsTextItem>


class Freebrigands: public QGraphicsTextItem{

  public:

    Freebrigands(QGraphicsItem * parent=0);
    void increase();
    int get();

private:
    int counter;

};


#endif // FREEBRIGANDS_H
