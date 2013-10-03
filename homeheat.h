#ifndef HOMEHEAT_H
#define HOMEHEAT_H

#include <QWidget>
#include <QString>

class HomeHeat : public QWidget
{
    Q_OBJECT
public:
    explicit HomeHeat(QWidget *parent = 0);

public:
    int     heat_consumption;
    double  heat_price;
    bool    gas;
    bool    oil;
    QString productionMean;
    bool    hotWater;

signals:

public slots:
    void setHeat_consumption(QString _new);
    void setHeat_price(QString _new);
    void setGas();
    void setOil();
    void setOtherMean();
    void setProductionMean(QString _new);
    void setHotWater(bool _new);
};

#endif // HOMEHEAT_H
