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

#endif // SCREENINDUSTRY1_H
