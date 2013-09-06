#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "industryconsumption.h"

IndustryConsumption::IndustryConsumption(QWidget *parent) :
    QWidget(parent)
{
    consumption = 0;
    hTArbPreis = 0;
    nTArbPreis = 0;
    netzkosten = 0;
    eEG = false;
    kWK = 0;
    stromstG = 0;
    offshore = 0;
    leistung = 0;

    QLabel *labelEnergy = new QLabel("<span style='font-size: 20pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *labelConsumption =  new QLabel("Consumption");          labelConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelHTArbPreis =   new QLabel("HT Arbeitspreis");      labelHTArbPreis->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelNTArbPreis =   new QLabel("NT Arbeitspreis");      labelNTArbPreis->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelNetzkosten =   new QLabel("Netzkosten");           labelNetzkosten->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelEEG =          new QLabel("EEG-Umlage-Befreit:");  labelEEG->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelKWK =          new QLabel("KWK");                  labelKWK->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelStromstG =     new QLabel("§19 Stromst-G.");       labelStromstG->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelOffshore =     new QLabel("OffshoreUmlage");       labelOffshore->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelLeistung =     new QLabel("Leistungskosten");      labelLeistung->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineConsumption =    new QLineEdit();
    QLabel *unitConsumption = new QLabel("kWh/year");

    QLineEdit *lineHTArbPreis =     new QLineEdit();
    QLabel *unitHTArbPreis = new QLabel("c€/kWh");

    QLineEdit *lineNTArbPreis =     new QLineEdit();
    QLabel *unitNTArbPreis = new QLabel("c€/kWh");

    QLineEdit *lineNetzkosten =     new QLineEdit();
    QLabel *unitNetzkosten = new QLabel("€/Monat");

    QLineEdit *lineKWK =            new QLineEdit();
    QLabel *unitKWK = new QLabel("€");

    QLineEdit *lineStromstG =       new QLineEdit();
    QLabel *unitStromstG = new QLabel("€");

    QLineEdit *lineOffshore =       new QLineEdit();
    QLabel *unitOffshore = new QLabel("€");

    QLineEdit *lineLeistung =       new QLineEdit();
    QLabel *unitLeistung = new QLabel("€/Monat");

    QCheckBox *radioEEG =           new QCheckBox();

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy,      0, 0, 1, 3);
    layout->addWidget(labelConsumption, 1, 0, 1, 1);
    layout->addWidget(labelHTArbPreis,  2, 0, 1, 1);
    layout->addWidget(labelNTArbPreis,  3, 0, 1, 1);
    layout->addWidget(labelNetzkosten,  4, 0, 1, 1);
    layout->addWidget(labelEEG,         5, 0, 1, 1);
    layout->addWidget(labelKWK,         6, 0, 1, 1);
    layout->addWidget(labelStromstG,    7, 0, 1, 1);
    layout->addWidget(labelOffshore,    8, 0, 1, 1);
    layout->addWidget(labelLeistung,    9, 0, 1, 1);

    layout->addWidget(lineConsumption,  1, 1, 1, 1);
    layout->addWidget(lineHTArbPreis,   2, 1, 1, 1);
    layout->addWidget(lineNTArbPreis,   3, 1, 1, 1);
    layout->addWidget(lineNetzkosten,   4, 1, 1, 1);
    layout->addWidget(radioEEG,         5, 1, 1, 1);
    layout->addWidget(lineKWK,          6, 1, 1, 1);
    layout->addWidget(lineStromstG,     7, 1, 1, 1);
    layout->addWidget(lineOffshore,     8, 1, 1, 1);
    layout->addWidget(lineLeistung,     9, 1, 1, 1);

    layout->addWidget(unitConsumption,  1, 2, 1, 1);
    layout->addWidget(unitHTArbPreis,   2, 2, 1, 1);
    layout->addWidget(unitNTArbPreis,   3, 2, 1, 1);
    layout->addWidget(unitNetzkosten,   4, 2, 1, 1);
    layout->addWidget(unitKWK,          6, 2, 1, 1);
    layout->addWidget(unitStromstG,     7, 2, 1, 1);
    layout->addWidget(unitOffshore,     8, 2, 1, 1);
    layout->addWidget(unitLeistung,     9, 2, 1, 1);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 2);
    layout->setColumnStretch(2, 1);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(10, 1);
    setLayout(layout);

    connect(lineConsumption,    SIGNAL(textEdited(QString)),    this, SLOT(setConsumption(QString)));
    connect(lineHTArbPreis,     SIGNAL(textEdited(QString)),    this, SLOT(setHTArbPreis(QString)));
    connect(lineNTArbPreis,     SIGNAL(textEdited(QString)),    this, SLOT(setNTArbPreis(QString)));
    connect(lineNetzkosten,     SIGNAL(textEdited(QString)),    this, SLOT(setNetzkosten(QString)));
    connect(radioEEG,           SIGNAL(clicked(bool)),          this, SLOT(setEEG(bool)));
    connect(lineKWK,            SIGNAL(textEdited(QString)),    this, SLOT(setKWK(QString)));
    connect(lineStromstG,       SIGNAL(textEdited(QString)),    this, SLOT(setStromstG(QString)));
    connect(lineOffshore,       SIGNAL(textEdited(QString)),    this, SLOT(setOffshore(QString)));
    connect(lineLeistung,       SIGNAL(textEdited(QString)),    this, SLOT(setLeistung(QString)));

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

void IndustryConsumption::setConsumption(QString _new)
{
    consumption = _new.toInt();
}

void IndustryConsumption::setHTArbPreis(QString _new)
{
    hTArbPreis = _new.toDouble();
}

void IndustryConsumption::setNTArbPreis(QString _new)
{
    nTArbPreis = _new.toDouble();
}

void IndustryConsumption::setNetzkosten(QString _new)
{
    netzkosten = _new.toDouble();
}

void IndustryConsumption::setEEG(bool _new)
{
    eEG = _new;
}

void IndustryConsumption::setKWK(QString _new)
{
    kWK = _new.toDouble();
}

void IndustryConsumption::setStromstG(QString _new)
{
    stromstG = _new.toDouble();
}

void IndustryConsumption::setOffshore(QString _new)
{
    offshore = _new.toDouble();
}

void IndustryConsumption::setLeistung(QString _new)
{
    leistung = _new.toDouble();
}
