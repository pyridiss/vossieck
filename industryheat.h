#ifndef INDUSTRYHEAT_H
#define INDUSTRYHEAT_H

#include <QWidget>

class IndustryHeat : public QWidget
{
    Q_OBJECT
public:
    explicit IndustryHeat(QWidget *parent = 0);

public:
    int     consumption;
    double  price;
    bool    gas;
    bool    oil;
    QString productionMean;

signals:

public slots:
    void setConsumption(QString _new);
    void setPrice(QString _new);
    void setGas();
    void setOil();
    void setOtherMean();
    void setProductionMean(QString _new);
};

#endif // INDUSTRYHEAT_H
