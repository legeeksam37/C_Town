#ifndef FREEWOMENCOUNTER_H
#define FREEWOMENCOUNTER_H
#include <QGraphicsTextItem>


class Freewomencounter: public QGraphicsTextItem{

  public:

    Freewomencounter(QGraphicsItem * parent=0);
    void increase();
    void increase(int i);
    int get();

private:
    int counter;

};
#endif // FREEWOMENCOUNTER_H
