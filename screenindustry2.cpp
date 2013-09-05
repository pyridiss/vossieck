#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "screenindustry2.h"

ScreenIndustry2::ScreenIndustry2(QWidget *parent) :
    QWidget(parent)
{
    consumption = 0;
    hTArbPreis = 0;
    nTArbPreis = 0;
    netzkosten = 0;
    checkedEEG = false;
    kWK = 0;
    stromstG = 0;
    offshore = 0;
    leistung = 0;

    QLabel *labelEnergy = new QLabel("<span style='font-size: 20pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *labelConsumption =  new QLabel("Consumption");
    QLabel *labelHTArbPreis =   new QLabel("HT Arbeitspreis");
    QLabel *labelNTArbPreis =   new QLabel("NT Arbeitspreis");
    QLabel *labelNetzkosten =   new QLabel("Netzkosten");
    QLabel *labelEEG =          new QLabel("EEG-Umlage-Befreit:");
    QLabel *labelKWK =          new QLabel("KWK");
    QLabel *labelStromstG =     new QLabel("§19 Stromst-G.");
    QLabel *labelOffshore =     new QLabel("OffshoreUmlage");
    QLabel *labelLeistung =     new QLabel("Leistungskosten");

    QLineEdit *lineConsumption =      new QLineEdit();
    QLabel *unitConsumption = new QLabel("kWh/year");

    QLineEdit *lineHTArbPreis = new QLineEdit();
    QLabel *unitHTArbPreis = new QLabel("c€/kWh");

    QLineEdit *lineNTArbPreis = new QLineEdit();
    QLabel *unitNTArbPreis = new QLabel("c€/kWh");

    QLineEdit *lineNetzkosten = new QLineEdit();
    QLabel *unitNetzkosten = new QLabel("€/Monat");

    QLineEdit *lineKWK =        new QLineEdit();
    QLabel *unitKWK = new QLabel("€");

    QLineEdit *lineStromstG =   new QLineEdit();
    QLabel *unitStromstG = new QLabel("€");

    QLineEdit *lineOffshore =   new QLineEdit();
    QLabel *unitOffshore = new QLabel("€");

    QLineEdit *lineLeistung =   new QLineEdit();
    QLabel *unitLeistung = new QLabel("€/Monat");

    QCheckBox *radioEEG =       new QCheckBox();

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy,      0, 0, 1, 3);
    layout->addWidget(labelConsumption, 1, 0, 1, 1);
    layout->addWidget(labelHTArbPreis,  2, 0, 1, 1);
    layout->addWidget(labelNTArbPreis,  3, 0, 1, 1);
    layout->addWidget(labelNetzkosten,  4, 0, 1, 1);
    layout->addWidget(labelEEG,         5, 0, 1, 2);
    layout->addWidget(labelKWK,         6, 0, 1, 1);
    layout->addWidget(labelStromstG,    7, 0, 1, 1);
    layout->addWidget(labelOffshore,    8, 0, 1, 1);
    layout->addWidget(labelLeistung,    9, 0, 1, 1);

    layout->addWidget(lineConsumption,  1, 1, 1, 1);
    layout->addWidget(lineHTArbPreis,   2, 1, 1, 1);
    layout->addWidget(lineNTArbPreis,   3, 1, 1, 1);
    layout->addWidget(lineNetzkosten,   4, 1, 1, 1);
    layout->addWidget(radioEEG,         5, 2, 1, 1);
    layout->addWidget(lineKWK,          6, 1, 1, 1);
    layout->addWidget(lineStromstG,     7, 1, 1, 1);
    layout->addWidget(lineOffshore,     8, 1, 1, 1);
    layout->addWidget(lineLeistung,     9, 1, 1, 1);

    layout->addWidget(unitConsumption,  1, 2, 1, 1);
    layout->addWidget(unitHTArbPreis,  2, 2, 1, 1);
    layout->addWidget(unitNTArbPreis,  3, 2, 1, 1);
    layout->addWidget(unitNetzkosten,  4, 2, 1, 1);
    layout->addWidget(unitKWK,  6, 2, 1, 1);
    layout->addWidget(unitStromstG,  7, 2, 1, 1);
    layout->addWidget(unitOffshore,  8, 2, 1, 1);
    layout->addWidget(unitLeistung,  9, 2, 1, 1);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(10, 1);
    setLayout(layout);
/*
    connect(lineConsumption,    SIGNAL(textEdited(QString)),      this, SLOT(setConsumption(int)));
    connect(lineHTArbPreis,     SIGNAL(valueChanged(double)),   this, SLOT(setHTArbPreis(double)));
    connect(lineNTArbPreis,     SIGNAL(valueChanged(double)),   this, SLOT(setNTArbPreis(double)));
    connect(lineNetzkosten,     SIGNAL(valueChanged(double)),   this, SLOT(setNetzkosten(double)));
    connect(radioEEG,           SIGNAL(clicked(bool)),          this, SLOT(setCheckedEEG(bool)));
    connect(lineKWK,            SIGNAL(valueChanged(double)),   this, SLOT(setKWK(double)));
    connect(lineStromstG,       SIGNAL(valueChanged(double)),   this, SLOT(setStromstG(double)));
    connect(lineOffshore,       SIGNAL(valueChanged(double)),   this, SLOT(setOffshore(double)));
    connect(lineLeistung,       SIGNAL(valueChanged(double)),   this, SLOT(setLeistung(double)));
*/
    //Signals to stop editing fields
    connect(lineConsumption,    SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineHTArbPreis,     SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineNTArbPreis,     SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineNetzkosten,     SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineKWK,            SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineStromstG,       SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineOffshore,       SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineLeistung,       SIGNAL(returnPressed()),      this, SLOT(setFocus()));
}

//Setters:

void ScreenIndustry2::setConsumption(int _new)
{
    consumption = _new;
}

void ScreenIndustry2::setHTArbPreis(double _new)
{
    hTArbPreis = _new;
}

void ScreenIndustry2::setNTArbPreis(double _new)
{
    nTArbPreis = _new;
}

void ScreenIndustry2::setNetzkosten(double _new)
{
    netzkosten = _new;
}

void ScreenIndustry2::setCheckedEEG(bool _new)
{
    checkedEEG = _new;
}

void ScreenIndustry2::setKWK(double _new)
{
    kWK = _new;
}

void ScreenIndustry2::setStromstG(double _new)
{
    stromstG = _new;
}

void ScreenIndustry2::setOffshore(double _new)
{
    offshore = _new;
}

void ScreenIndustry2::setLeistung(double _new)
{
    leistung = _new;
}
