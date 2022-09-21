#ifndef WOMEN_H
#define WOMEN_H


#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>



class Dame : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT

  public :
    int Rand(int a, int b);
    Dame(QGraphicsItem * parent = 0);
public slots:
    void Appears();
};


#endif // WOMEN_H
