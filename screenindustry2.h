#ifndef SCREENINDUSTRY2_H
#define SCREENINDUSTRY2_H

#include <QWidget>

class ScreenIndustry2 : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenIndustry2(QWidget *parent = 0);

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
    void setConsumption(QString _new);
    void setHTArbPreis(QString _new);
    void setNTArbPreis(QString _new);
    void setNetzkosten(QString _new);
    void setCheckedEEG(bool _new);
    void setKWK(QString _new);
    void setStromstG(QString _new);
    void setOffshore(QString _new);
    void setLeistung(QString _new);
};

#endif // SCREENINDUSTRY2_H
