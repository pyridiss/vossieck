#ifndef INDUSTRYSTEAM_H
#define INDUSTRYSTEAM_H

#include <QWidget>
#include <QString>

class IndustrySteam : public QWidget
{
    Q_OBJECT
public:
    explicit IndustrySteam(QWidget *parent = 0);

public:
    bool steam;
    double pressure;
    int consumption;
    int temperature;
    bool gas;
    bool oil;
    QString productionMean;

signals:

public slots:
    void setSteamYes();
    void setSteamNo();
    void setPressure(QString _new);
    void setConsumption(QString _new);
    void setTemperature(QString _new);
    void setGas();
    void setOil();
    void setOtherMean();
    void setProductionMean(QString _new);
};

#endif // INDUSTRYSTEAM_H
