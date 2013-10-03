#ifndef HOMEELECTRICITY_H
#define HOMEELECTRICITY_H

#include <QWidget>

class HomeElectricity : public QWidget
{
    Q_OBJECT
public:
    explicit HomeElectricity(QWidget *parent = 0);

public:
    int     energy_consumption;
    double  energy_price;
    double  energy_basePrice;

signals:

public slots:
    void setEnergy_consumption(QString _new);
    void setEnergy_price(QString _new);
    void setEnergy_basePrice(QString _new);
};

#endif // HOMEELECTRICITY_H
