#ifndef FINALSCREEN_H
#define FINALSCREEN_H

#include <QWidget>
#include <QLabel>

class FinalScreen : public QWidget
{
    Q_OBJECT
public:
    explicit FinalScreen(QWidget *parent = 0);

public:
    void setDataString(QString _new);

public:
    QString data;
    QLabel *labelError;

signals:
    
public slots:
    void sendData();
};

#endif // FINALSCREEN_H
