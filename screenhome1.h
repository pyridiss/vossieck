#ifndef SCREENHOME1_H
#define SCREENHOME1_H

#include <QWidget>

class ScreenHome1 : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenHome1(QWidget *parent = 0);

private:
    int     energy_kWhPerYear;
    double  energy_pricePerkWh;
    double  energy_basePrice;
    int     heat_kWhPerYear;
    double  heat_pricePerkWh;
    bool    gasSelected;
    bool    withHotWater;

public:
    int     getEnergy_kWhPerYear();
    double  getEnergy_pricePerkWh();
    double  getEnergy_basePrice();
    int     getHeat_kWhPerYear();
    double  getHeat_pricePerkWh();
    bool    getGasSelected();
    bool    getWithHotWater();

signals:

public slots:
    void setEnergy_kWhPerYear(int _new);
    void setEnergy_pricePerkWh(double _new);
    void setEnergy_basePrice(double _new);
    void setHeat_kWhPerYear(int _new);
    void setHeat_pricePerkWh(double _new);
    void checkGas();
    void checkOil();
    void checkHotWater(bool _new);
};

#endif // SCREENHOME1_H
