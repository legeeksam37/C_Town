#ifndef WOMEN_H
#define WOMEN_H



#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Women : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT

  public :
    Women(QGraphicsItem * parent=0);
    ~Women();
public slots:
    void appears();

};


#endif // WOMEN_H
