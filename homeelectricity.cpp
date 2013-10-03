#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>

#include "homeelectricity.h"

HomeElectricity::HomeElectricity(QWidget *parent) :
    QWidget(parent)
{
    energy_consumption = 0;
    energy_price = 0;
    energy_basePrice = 0;

    QLabel *labelEnergy = new QLabel("<span style='font-size: 20pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelEnergyConsumption = new QLabel("Consumption"); labelEnergyConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelEnergyPrice       = new QLabel("Price");       labelEnergyPrice->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelEnergyBasePrice   = new QLabel("Base Price");  labelEnergyBasePrice->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineEnergyConsumption    = new QLineEdit();
    QLabel *unitEnergyConsumption       = new QLabel("kWh/Year");

    QLineEdit *lineEnergyPrice          = new QLineEdit();
    QLabel *unitEnergyPrice             = new QLabel("c€/kWh");

    QLineEdit *lineEnergyBasePrice      = new QLineEdit();
    QLabel *unitEnergyBasePrice         = new QLabel("€/Month");


    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy,              0, 0, 1, 4);
    layout->addWidget(labelEnergyConsumption,   1, 0, 1, 1);
    layout->addWidget(labelEnergyPrice,         2, 0, 1, 1);
    layout->addWidget(labelEnergyBasePrice,     3, 0, 1, 1);
    layout->addWidget(lineEnergyConsumption,    1, 1, 1, 2);
    layout->addWidget(lineEnergyPrice,          2, 1, 1, 2);
    layout->addWidget(lineEnergyBasePrice,      3, 1, 1, 2);
    layout->addWidget(unitEnergyConsumption,    1, 3, 1, 1);
    layout->addWidget(unitEnergyPrice,          2, 3, 1, 1);
    layout->addWidget(unitEnergyBasePrice,      3, 3, 1, 1);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    setLayout(layout);

    connect(lineEnergyConsumption,  SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_consumption(QString)));
    connect(lineEnergyPrice,        SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_price(QString)));
    connect(lineEnergyBasePrice,    SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_basePrice(QString)));

    //Signals to stop editing fields
    connect(lineEnergyConsumption,  SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineEnergyPrice,        SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineEnergyBasePrice,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}

//Setters:

void HomeElectricity::setEnergy_consumption(QString _new)
{
    energy_consumption = _new.toInt();
}

void HomeElectricity::setEnergy_price(QString _new)
{
    energy_price = _new.toDouble();
}

void HomeElectricity::setEnergy_basePrice(QString _new)
{
    energy_basePrice = _new.toDouble();
}
