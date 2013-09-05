#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
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

    QLabel *labelEnergyConsumption = new QLabel("Consumption");
    QLabel *labelEnergyPrice       = new QLabel("Price");
    QLabel *labelEnergyBasePrice   = new QLabel("Base Price");

    QSpinBox *lineEnergyConsumption     = new QSpinBox();
    lineEnergyConsumption->setRange(0, 100000); lineEnergyConsumption->setSingleStep(10);
    lineEnergyConsumption->setAccelerated(true);
    lineEnergyConsumption->setSuffix(" kWh/Year");

    QDoubleSpinBox *lineEnergyPrice     = new QDoubleSpinBox();
    lineEnergyPrice->setRange(0, 100);          lineEnergyPrice->setSingleStep(0.01);
    lineEnergyPrice->setAccelerated(true);
    lineEnergyPrice->setSuffix(" c€/kWh");

    QDoubleSpinBox *lineEnergyBasePrice = new QDoubleSpinBox();
    lineEnergyBasePrice->setRange(0, 10000);    lineEnergyBasePrice->setSingleStep(0.01);
    lineEnergyBasePrice->setAccelerated(true);
    lineEnergyBasePrice->setSuffix(" €/Month");


    QLabel *labelHeat = new QLabel("<span style='font-size: 20pt;'>Heat</span>");
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelHeatConsumption = new QLabel("Consumption");
    QLabel *labelHeatPrice       = new QLabel("Price");

    QSpinBox *lineHeatConsumption = new QSpinBox();
    lineHeatConsumption->setRange(0, 100000);   lineHeatConsumption->setSingleStep(10);
    lineHeatConsumption->setAccelerated(true);
    lineHeatConsumption->setSuffix(" kWh/year");

    QDoubleSpinBox *lineHeatPrice = new QDoubleSpinBox();
    lineHeatPrice->setRange(0, 100);            lineHeatPrice->setSingleStep(0.01);
    lineHeatPrice->setAccelerated(true);
    lineHeatPrice->setSuffix(" c€/kWh");

    QLabel *labelFuel = new QLabel("Fuel:");
    QRadioButton* radioGas = new QRadioButton("Gas");
    QRadioButton* radioOil = new QRadioButton("Oil");
    QCheckBox* checkHotWater = new QCheckBox("Hot Water included");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy, 0, 0, 1, 3);
    layout->addWidget(labelEnergyConsumption, 1, 0, 1, 1);
    layout->addWidget(labelEnergyPrice, 2, 0, 1, 1);
    layout->addWidget(labelEnergyBasePrice, 3, 0, 1, 1);
    layout->addWidget(lineEnergyConsumption, 1, 1, 1, 2);
    layout->addWidget(lineEnergyPrice, 2, 1, 1, 2);
    layout->addWidget(lineEnergyBasePrice, 3, 1, 1, 2);

    layout->addWidget(labelHeat, 4, 0, 1, 3);
    layout->addWidget(labelHeatConsumption, 5, 0, 1, 1);
    layout->addWidget(labelHeatPrice, 6, 0, 1, 1);
    layout->addWidget(lineHeatConsumption, 5, 1, 1, 2);
    layout->addWidget(lineHeatPrice, 6, 1, 1, 2);
    layout->addWidget(labelFuel, 7, 0, 2, 1);
    layout->addWidget(radioGas, 7, 1, 1, 1);
    layout->addWidget(radioOil, 7, 2, 1, 1);
    layout->addWidget(checkHotWater, 8, 1, 1, 2);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    layout->setRowStretch(9, 1);
    setLayout(layout);

    connect(lineEnergyConsumption,  SIGNAL(valueChanged(int)),      this, SLOT(setEnergy_consumption(int)));
    connect(lineEnergyPrice,        SIGNAL(valueChanged(double)),   this, SLOT(setEnergy_price(double)));
    connect(lineEnergyBasePrice,    SIGNAL(valueChanged(double)),   this, SLOT(setEnergy_basePrice(double)));
    connect(lineHeatConsumption,    SIGNAL(valueChanged(int)),      this, SLOT(setHeat_consumption(int)));
    connect(lineHeatPrice,          SIGNAL(valueChanged(double)),   this, SLOT(setHeat_price(double)));
    connect(radioGas,               SIGNAL(clicked()),              this, SLOT(setGas()));
    connect(radioOil,               SIGNAL(clicked()),              this, SLOT(setOil()));
    connect(checkHotWater,          SIGNAL(clicked(bool)),          this, SLOT(setHotWater(bool)));

    //Signals to stop editing fields
    connect(lineEnergyConsumption,  SIGNAL(editingFinished()),      this, SLOT(setFocus()));
    connect(lineEnergyPrice,        SIGNAL(editingFinished()),      this, SLOT(setFocus()));
    connect(lineEnergyBasePrice,    SIGNAL(editingFinished()),      this, SLOT(setFocus()));
    connect(lineHeatConsumption,    SIGNAL(editingFinished()),      this, SLOT(setFocus()));
    connect(lineHeatPrice,          SIGNAL(editingFinished()),      this, SLOT(setFocus()));
}

//Setters:

void HomeConsumption::setEnergy_consumption(int _new)
{
    energy_consumption = _new;
}

void HomeConsumption::setEnergy_price(double _new)
{
    energy_price = _new;
}

void HomeConsumption::setEnergy_basePrice(double _new)
{
    energy_basePrice = _new;
}

void HomeConsumption::setHeat_consumption(int _new)
{
    heat_consumption = _new;
}

void HomeConsumption::setHeat_price(double _new)
{
    heat_price = _new;
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
