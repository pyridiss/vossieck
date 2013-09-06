#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>

#include "homeconsumption.h"

HomeConsumption::HomeConsumption(QWidget *parent) :
    QWidget(parent)
{
    energy_consumption = 0;
    energy_price = 0;
    energy_basePrice = 0;
    heat_consumption = 0;
    heat_price = 0;
    gas = false;
    oil = false;
    hotWater = false;

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


    QLabel *labelHeat = new QLabel("<span style='font-size: 20pt;'>Heat</span>");
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelHeatConsumption = new QLabel("Consumption");   labelHeatConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelHeatPrice       = new QLabel("Price");         labelHeatPrice->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineHeatConsumption  = new QLineEdit();
    QLabel *unitHeatConsumption     = new QLabel("kWh/year");

    QLineEdit *lineHeatPrice        = new QLineEdit();
    QLabel *unitHeatPrice           = new QLabel("c€/kWh");

    QLabel *labelFuel = new QLabel("Fuel:");                    labelFuel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QRadioButton* radioGas = new QRadioButton("Gas");
    QRadioButton* radioOil = new QRadioButton("Oil");
    QCheckBox* checkHotWater = new QCheckBox("Hot Water included");

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

    layout->addWidget(labelHeat,                4, 0, 1, 4);
    layout->addWidget(labelHeatConsumption,     5, 0, 1, 1);
    layout->addWidget(labelHeatPrice,           6, 0, 1, 1);
    layout->addWidget(lineHeatConsumption,      5, 1, 1, 2);
    layout->addWidget(lineHeatPrice,            6, 1, 1, 2);
    layout->addWidget(unitHeatConsumption,      5, 3, 1, 1);
    layout->addWidget(unitHeatPrice,            6, 3, 1, 1);
    layout->addWidget(labelFuel,                7, 0, 2, 1);
    layout->addWidget(radioGas,                 7, 1, 1, 1);
    layout->addWidget(radioOil,                 7, 2, 1, 1);
    layout->addWidget(checkHotWater,            8, 1, 1, 2);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    layout->setRowStretch(9, 1);
    setLayout(layout);

    connect(lineEnergyConsumption,  SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_consumption(QString)));
    connect(lineEnergyPrice,        SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_price(QString)));
    connect(lineEnergyBasePrice,    SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_basePrice(QString)));
    connect(lineHeatConsumption,    SIGNAL(textEdited(QString)),    this, SLOT(setHeat_consumption(QString)));
    connect(lineHeatPrice,          SIGNAL(textEdited(QString)),    this, SLOT(setHeat_price(QString)));
    connect(radioGas,               SIGNAL(clicked()),              this, SLOT(setGas()));
    connect(radioOil,               SIGNAL(clicked()),              this, SLOT(setOil()));
    connect(checkHotWater,          SIGNAL(clicked(bool)),          this, SLOT(setHotWater(bool)));

    //Signals to stop editing fields
    connect(lineEnergyConsumption,  SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineEnergyPrice,        SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineEnergyBasePrice,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineHeatConsumption,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineHeatPrice,          SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}

//Setters:

void HomeConsumption::setEnergy_consumption(QString _new)
{
    energy_consumption = _new.toInt();
}

void HomeConsumption::setEnergy_price(QString _new)
{
    energy_price = _new.toDouble();
}

void HomeConsumption::setEnergy_basePrice(QString _new)
{
    energy_basePrice = _new.toDouble();
}

void HomeConsumption::setHeat_consumption(QString _new)
{
    heat_consumption = _new.toInt();
}

void HomeConsumption::setHeat_price(QString _new)
{
    heat_price = _new.toDouble();
}

void HomeConsumption::setGas()
{
    gas = true;
    oil = false;
}

void HomeConsumption::setOil()
{
    gas = false;
    oil = true;
}

void HomeConsumption::setHotWater(bool _new)
{
    hotWater = _new;
}
