#ifndef SCREENHOME2_H
#define SCREENHOME2_H

#include <QWidget>

class ScreenHome2 : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenHome2(QWidget *parent = 0);

private:
    QString surface;
    QString direction;
    QString angle;

public:
    double  getSurface();
    QString getDirection();
    int     getAngle();

signals:

public slots:
    void setSurface(QString _new);
    void setDirection(QString _new);
    void setAngle(QString _new);
};

#endif // SCREENHOME2_H
