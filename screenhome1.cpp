#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "screenhome1.h"

ScreenHome1::ScreenHome1(QWidget *parent) :
    QWidget(parent)
{
    gasSelected = false;
    withHotWater = false;

    QLabel *labelEnergy = new QLabel("<span style='font-size: 20pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelEnergykWhPerYear = new QLabel("Consumption <span style='font-size:10pt;'>(kWh/Year)</span>");
    QLabel *labelEnergyPricePerkWh = new QLabel("Price <span style='font-size:10pt;'>(c€/kWh)</span>");
    QLabel *labelEnergyBasePrice = new QLabel("Base Price <span style='font-size:10pt;'>(€/Month)</span>");

    QSpinBox *lineEnergykWhPerYear =        new QSpinBox();
    lineEnergykWhPerYear->setRange(1000, 1000000);  lineEnergykWhPerYear->setSingleStep(500);
    QDoubleSpinBox *lineEnergyPricePerkWh = new QDoubleSpinBox();
    lineEnergyPricePerkWh->setRange(1000, 1000000); lineEnergyPricePerkWh->setSingleStep(500);
    QDoubleSpinBox *lineEnergyBasePrice =   new QDoubleSpinBox();
    lineEnergyBasePrice->setRange(1000, 1000000);   lineEnergyBasePrice->setSingleStep(500);

 //   QLineEdit *lineEnergykWhPerYear = new QLineEdit();
 //   QLineEdit *lineEnergyPricePerkWh = new QLineEdit();
 //   QLineEdit *lineEnergyBasePrice = new QLineEdit();


    QLabel *labelHeat = new QLabel("<span style='font-size: 20pt;'>Heat</span>");
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelHeatkWhPerYear = new QLabel("Consumption <span style='font-size:10pt;'>(kWh/Year)</span>");
    QLabel *labelHeatPricePerkWh = new QLabel("Price <span style='font-size:10pt;'>(c€/kWh)</span>");

    QSpinBox *lineHeatkWhPerYear =        new QSpinBox();
    lineHeatkWhPerYear->setRange(1000, 1000000);  lineHeatkWhPerYear->setSingleStep(500);
    QDoubleSpinBox *lineHeatPricePerkWh = new QDoubleSpinBox();
    lineHeatPricePerkWh->setRange(1000, 1000000); lineHeatPricePerkWh->setSingleStep(500);

//    QLineEdit *lineHeatkWhPerYear = new QLineEdit();
//    QLineEdit *lineHeatPricePerkWh = new QLineEdit();

    QLabel *labelFuel = new QLabel("Fuel:");
    QRadioButton* radioGas = new QRadioButton("Gas");
    QRadioButton* radioOil = new QRadioButton("Oil");
    QCheckBox* checkHotWater = new QCheckBox("Hot Water included");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelEnergy, 0, 0, 1, 3);
    layout->addWidget(labelEnergykWhPerYear, 1, 0, 1, 1);
    layout->addWidget(labelEnergyPricePerkWh, 2, 0, 1, 1);
    layout->addWidget(labelEnergyBasePrice, 3, 0, 1, 1);
    layout->addWidget(lineEnergykWhPerYear, 1, 1, 1, 2);
    layout->addWidget(lineEnergyPricePerkWh, 2, 1, 1, 2);
    layout->addWidget(lineEnergyBasePrice, 3, 1, 1, 2);

    layout->addWidget(labelHeat, 4, 0, 1, 3);
    layout->addWidget(labelHeatkWhPerYear, 5, 0, 1, 1);
    layout->addWidget(labelHeatPricePerkWh, 6, 0, 1, 1);
    layout->addWidget(lineHeatkWhPerYear, 5, 1, 1, 2);
    layout->addWidget(lineHeatPricePerkWh, 6, 1, 1, 2);
    layout->addWidget(labelFuel, 7, 0, 2, 1);
    layout->addWidget(radioGas, 7, 1, 1, 1);
    layout->addWidget(radioOil, 7, 2, 1, 1);
    layout->addWidget(checkHotWater, 8, 1, 1, 2);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    layout->setRowStretch(9, 1);
    setLayout(layout);

    connect(lineEnergykWhPerYear,   SIGNAL(valueChanged(int)),      this, SLOT(setEnergy_kWhPerYear(int)));
    connect(lineEnergyPricePerkWh,  SIGNAL(valueChanged(double)),   this, SLOT(setEnergy_pricePerkWh(double)));
    connect(lineEnergyBasePrice,    SIGNAL(valueChanged(double)),   this, SLOT(setEnergy_basePrice(double)));
    connect(lineHeatkWhPerYear,     SIGNAL(valueChanged(int)),      this, SLOT(setHeat_kWhPerYear(int)));
    connect(lineHeatPricePerkWh,    SIGNAL(valueChanged(double)),   this, SLOT(setHeat_pricePerkWh(double)));
    connect(radioGas,               SIGNAL(clicked()),              this, SLOT(checkGas()));
    connect(radioOil,               SIGNAL(clicked()),              this, SLOT(checkOil()));
    connect(checkHotWater,          SIGNAL(clicked(bool)),          this, SLOT(checkHotWater(bool)));
}

//Setters:

void ScreenHome1::setEnergy_kWhPerYear(int _new)
{
    energy_kWhPerYear = _new;
}

void ScreenHome1::setEnergy_pricePerkWh(double _new)
{
    energy_pricePerkWh = _new;
}

void ScreenHome1::setEnergy_basePrice(double _new)
{
    energy_basePrice = _new;
}

void ScreenHome1::setHeat_kWhPerYear(int _new)
{
    heat_kWhPerYear = _new;
}

void ScreenHome1::setHeat_pricePerkWh(double _new)
{
    heat_pricePerkWh = _new;
}

void ScreenHome1::checkGas()
{
    gasSelected = true;
}

void ScreenHome1::checkOil()
{
    gasSelected = false;
}

void ScreenHome1::checkHotWater(bool _new)
{
    withHotWater = _new;
}

//Getters:

int ScreenHome1::getEnergy_kWhPerYear()
{
    return energy_kWhPerYear;
}

double ScreenHome1::getEnergy_pricePerkWh()
{
    return energy_pricePerkWh;
}

double ScreenHome1::getEnergy_basePrice()
{
    return energy_pricePerkWh;
}

int ScreenHome1::getHeat_kWhPerYear()
{
    return heat_kWhPerYear;
}

double ScreenHome1::getHeat_pricePerkWh()
{
    return heat_pricePerkWh;
}

bool ScreenHome1::getGasSelected()
{
    return gasSelected;
}

bool ScreenHome1::getWithHotWater()
{
    return withHotWater;
}
