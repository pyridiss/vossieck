#ifndef FINALSCREEN_H
#define FINALSCREEN_H

#include <QWidget>

class FinalScreen : public QWidget
{
    Q_OBJECT
public:
    explicit FinalScreen(QWidget *parent = 0);

public:
    void setDataString(QString _new);

public:
    QString data;

signals:
    
public slots:
    
};

#endif // FINALSCREEN_H
