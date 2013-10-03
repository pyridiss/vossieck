#ifndef HOMECONSUMPTION_H
#define HOMECONSUMPTION_H

#include <QWidget>

class HomeConsumption : public QWidget
{
    Q_OBJECT
public:
    explicit HomeConsumption(QWidget *parent = 0);

public:
    int     energy_consumption;
    double  energy_price;
    double  energy_basePrice;
    int     heat_consumption;
    double  heat_price;
    bool    gas;
    bool    oil;
    bool    hotWater;

signals:

public slots:
    void setEnergy_consumption(QString _new);
    void setEnergy_price(QString _new);
    void setEnergy_basePrice(QString _new);
    void setHeat_consumption(QString _new);
    void setHeat_price(QString _new);
    void setGas();
    void setOil();
    void setHotWater(bool _new);
};

#endif // HOMECONSUMPTION_H
