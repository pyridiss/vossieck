#ifndef SCREENHOME2_H
#define SCREENHOME2_H

#include <QWidget>

class HomePV : public QWidget
{
    Q_OBJECT

public:
    explicit HomePV(QWidget *parent = 0);

public:
    int     surface;
    QString direction;
    int     angle;

signals:

public slots:
    void setSurface(QString _new);
    void setDirection(QString _new);
    void setAngle(QString _new);
};

#endif // SCREENHOME2_H
