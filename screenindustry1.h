#ifndef SCREENINDUSTRY1_H
#define SCREENINDUSTRY1_H

#include <QWidget>

class ScreenIndustry1 : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenIndustry1(QWidget *parent = 0);

private:
    int    consumption;
    double hTArbPreis;
    double nTArbPreis;
    double netzkosten;
    bool   checkedEEG;
    double kWK;
    double stromstG;
    double offshore;
    double leistung;

public:
    int     getConsumption();
    double  getHTArbPreis();
    double  getNTArbPreis();
    double  getNetzkosten();
    bool    getCheckedEEG();
    double  getKWK();
    double  getStromstG();
    double  getOffshore();
    double  getLeistung();

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
