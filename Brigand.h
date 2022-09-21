#ifndef BRIGAND_H
#define BRIGAND_H


#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Brigand : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT

  public :
    int Rand(int a, int b);
    Brigand(QGraphicsItem * parent=0);
    ~Brigand();
public slots:
    void move();

};


#endif // BRIGAND_H
