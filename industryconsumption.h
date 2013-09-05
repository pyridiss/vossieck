#ifndef SCREENINDUSTRY1_H
#define SCREENINDUSTRY1_H

#include <QWidget>

class IndustryConsumption : public QWidget
{
    Q_OBJECT
public:
    explicit IndustryConsumption(QWidget *parent = 0);

public:
    int    consumption;
    double hTArbPreis;
    double nTArbPreis;
    double netzkosten;
    bool   checkedEEG;
    double kWK;
    double stromstG;
    double offshore;
    double leistung;

signals:

public slots:
    void setConsumption(int _new);
    void setHTArbPreis(double _new);
    void setNTArbPreis(double _new);
    void setNetzkosten(double _new);
    void setCheckedEEG(bool _new);
    void setKWK(double _new);
    void setStromstG(double _new);
    void setOffshore(double _new);
    void setLeistung(double _new);
};

#endif // SCREENINDUSTRY1_H
