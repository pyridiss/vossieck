#ifndef SCREENHOME1_H
#define SCREENHOME1_H

#include <QWidget>

class ScreenHome1 : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenHome1(QWidget *parent = 0);

private:
    QString energy_kWhPerYear;
    QString energy_pricePerkWh;
    QString energy_basePrice;
    QString heat_kWhPerYear;
    QString heat_pricePerkWh;
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
    void setEnergy_kWhPerYear(QString _new);
    void setEnergy_pricePerkWh(QString _new);
    void setEnergy_basePrice(QString _new);
    void setHeat_kWhPerYear(QString _new);
    void setHeat_pricePerkWh(QString _new);
    void checkGas();
    void checkOil();
    void checkHotWater(bool _new);
};

#endif // SCREENHOME1_H
