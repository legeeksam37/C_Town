#ifndef BALLE_H
#define BALLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>



class Balle : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT

  public :
    Balle(QGraphicsItem * parent = 0);
public slots:
    void move();
};

#endif // BALLE_H
