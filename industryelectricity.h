#ifndef INDUSTRYELECTRICITY_H
#define INDUSTRYELECTRICITY_H

#include <QWidget>

class IndustryElectricity : public QWidget
{
    Q_OBJECT
public:
    explicit IndustryElectricity(QWidget *parent = 0);

public:
    int    consumption;
    double hTArbPreis;
    double nTArbPreis;
    double netzkosten;
    bool   eEG;
    double kWK;
    double stromstG;
    double offshore;
    double leistung;

signals:

public slots:
    void setConsumption(QString _new);
    void setHTArbPreis(QString _new);
    void setNTArbPreis(QString _new);
    void setNetzkosten(QString _new);
    void setEEG(bool _new);
    void setKWK(QString _new);
    void setStromstG(QString _new);
    void setOffshore(QString _new);
    void setLeistung(QString _new);
};

#endif // INDUSTRYELECTRICITY_H
