#ifndef SCREENHOME1_H
#define SCREENHOME1_H

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
    bool    gasSelected;
    bool    withHotWater;

signals:

public slots:
    void setEnergy_consumption(int _new);
    void setEnergy_price(double _new);
    void setEnergy_basePrice(double _new);
    void setHeat_consumption(int _new);
    void setHeat_price(double _new);
    void checkGas();
    void checkOil();
    void checkHotWater(bool _new);
};

#endif // SCREENHOME1_H
