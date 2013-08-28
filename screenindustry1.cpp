#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "screenindustry1.h"

ScreenIndustry1::ScreenIndustry1(QWidget *parent) :
    QWidget(parent)
{
    checkedEEG = false;

    QLabel *labelEnergy = new QLabel("<span style='font-size: 20pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *labelkWhPerYear =   new QLabel("Consumption <span style='font-size:10pt;'>(kWh/Year)</span>");
    QLabel *labelHTArbPreis =   new QLabel("HT Arbeitspreis <span style='font-size:10pt;'>(c€/kWh)</span>");
    QLabel *labelNTArbPreis =   new QLabel("HT Arbeitspreis <span style='font-size:10pt;'>(c€/kWh)</span>");
    QLabel *labelNetzkosten =   new QLabel("Netzkosten <span style='font-size:10pt;'>(€/?)</span>");
    QLabel *labelEEG =          new QLabel("EEG-Umlage-Befreit:");
    QLabel *labelKWK =          new QLabel("KWK");
    QLabel *labelStromstG =     new QLabel("§19 Stromst-G.");
    QLabel *labelOffshore =     new QLabel("OffshoreUmlage");
    QLabel *labelLeistung =     new QLabel("Leistungskosten");

    QSpinBox *linekWhPerYear =       new QSpinBox();
    linekWhPerYear->setRange(1000, 1000000);    linekWhPerYear->setSingleStep(500);
    QDoubleSpinBox *lineHTArbPreis = new QDoubleSpinBox();
    lineHTArbPreis->setRange(1000, 1000000);    lineHTArbPreis->setSingleStep(500);
    QDoubleSpinBox *lineNTArbPreis = new QDoubleSpinBox();
    lineNTArbPreis->setRange(1000, 1000000);    lineNTArbPreis->setSingleStep(500);
    QDoubleSpinBox *lineNetzkosten = new QDoubleSpinBox();
    lineNetzkosten->setRange(1000, 1000000);    lineNetzkosten->setSingleStep(500);
    QDoubleSpinBox *lineKWK =        new QDoubleSpinBox();
    lineKWK->setRange(1000, 1000000);           lineKWK->setSingleStep(500);
    QDoubleSpinBox *lineStromstG =   new QDoubleSpinBox();
    lineStromstG->setRange(1000, 1000000);      lineStromstG->setSingleStep(500);
    QDoubleSpinBox *lineOffshore =   new QDoubleSpinBox();
    lineOffshore->setRange(1000, 1000000);      lineOffshore->setSingleStep(500);
    QDoubleSpinBox *lineLeistung =   new QDoubleSpinBox();
    lineLeistung->setRange(1000, 1000000);      lineLeistung->setSingleStep(500);

    QCheckBox *radioEEG =       new QCheckBox();

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy,      0, 0, 1, 2);
    layout->addWidget(labelkWhPerYear,  1, 0, 1, 1);
    layout->addWidget(labelHTArbPreis,  2, 0, 1, 1);
    layout->addWidget(labelNTArbPreis,  3, 0, 1, 1);
    layout->addWidget(labelNetzkosten,  4, 0, 1, 1);
    layout->addWidget(labelEEG,         5, 0, 1, 1);
    layout->addWidget(labelKWK,         6, 0, 1, 1);
    layout->addWidget(labelStromstG,    7, 0, 1, 1);
    layout->addWidget(labelOffshore,    8, 0, 1, 1);
    layout->addWidget(labelLeistung,    9, 0, 1, 1);


    layout->addWidget(linekWhPerYear,   1, 1, 1, 1);
    layout->addWidget(lineHTArbPreis,   2, 1, 1, 1);
    layout->addWidget(lineNTArbPreis,   3, 1, 1, 1);
    layout->addWidget(lineNetzkosten,   4, 1, 1, 1);

    layout->addWidget(radioEEG,         5, 1, 1, 1);

    layout->addWidget(lineKWK,          6, 1, 1, 1);
    layout->addWidget(lineStromstG,     7, 1, 1, 1);
    layout->addWidget(lineOffshore,     8, 1, 1, 1);
    layout->addWidget(lineLeistung,     9, 1, 1, 1);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(10, 1);
    setLayout(layout);

    connect(linekWhPerYear, SIGNAL(valueChanged(int)),      this, SLOT(setkWhPerYear(int)));
    connect(lineHTArbPreis, SIGNAL(valueChanged(double)),   this, SLOT(setHTArbPreis(double)));
    connect(lineNTArbPreis, SIGNAL(valueChanged(double)),   this, SLOT(setNTArbPreis(double)));
    connect(lineNetzkosten, SIGNAL(valueChanged(double)),   this, SLOT(setNetzkosten(double)));
    connect(radioEEG,       SIGNAL(clicked(bool)),          this, SLOT(setCheckedEEG(bool)));
    connect(lineKWK,        SIGNAL(valueChanged(double)),   this, SLOT(setKWK(double)));
    connect(lineStromstG,   SIGNAL(valueChanged(double)),   this, SLOT(setStromstG(double)));
    connect(lineOffshore,   SIGNAL(valueChanged(double)),   this, SLOT(setOffshore(double)));
    connect(lineLeistung,   SIGNAL(valueChanged(double)),   this, SLOT(setLeistung(double)));
}

//Getters:

int     ScreenIndustry1::getkWhPerYear()
{
    return kWhPerYear;
}

double  ScreenIndustry1::getHTArbPreis()
{
    return hTArbPreis;
}

double  ScreenIndustry1::getNTArbPreis()
{
    return nTArbPreis;
}

double  ScreenIndustry1::getNetzkosten()
{
    return netzkosten;
}

bool    ScreenIndustry1::getCheckedEEG()
{
    return checkedEEG;
}

double  ScreenIndustry1::getKWK()
{
    return kWK;
}

double  ScreenIndustry1::getStromstG()
{
    return stromstG;
}

double  ScreenIndustry1::getOffshore()
{
    return offshore;
}

double  ScreenIndustry1::getLeistung()
{
    return leistung;
}

//Setters:

void ScreenIndustry1::setkWhPerYear(int _new)
{
    kWhPerYear = _new;
}

void ScreenIndustry1::setHTArbPreis(double _new)
{
    hTArbPreis = _new;
}

void ScreenIndustry1::setNTArbPreis(double _new)
{
    nTArbPreis = _new;
}

void ScreenIndustry1::setNetzkosten(double _new)
{
    netzkosten = _new;
}

void ScreenIndustry1::setCheckedEEG(bool _new)
{
    checkedEEG = _new;
}

void ScreenIndustry1::setKWK(double _new)
{
    kWK = _new;
}

void ScreenIndustry1::setStromstG(double _new)
{
    stromstG = _new;
}

void ScreenIndustry1::setOffshore(double _new)
{
    offshore = _new;
}

void ScreenIndustry1::setLeistung(double _new)
{
    leistung = _new;
}