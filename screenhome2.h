#ifndef SCREENHOME2_H
#define SCREENHOME2_H

#include <QWidget>

class ScreenHome2 : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenHome2(QWidget *parent = 0);

public:
    int     surface;
    QString direction;
    int     angle;

signals:

public slots:
    void setSurface(int _new);
    void setDirection(QString _new);
    void setAngle(int _new);
};

#endif // SCREENHOME2_H
