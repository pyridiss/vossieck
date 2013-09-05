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
    QString name;
    QString adress;
    QString phone;
    QString email;

public:
    void setDataString(QString _new);

public:
    QString data;
    QLabel *labelError;

signals:
    
public slots:
    void sendData();
    void setName(QString _new);
    void setAdress(QString _new);
    void setPhone(QString _new);
    void setEmail(QString _new);
};

#endif // FINALSCREEN_H
