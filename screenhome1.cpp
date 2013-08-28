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

    QLabel *labelEnergy = new QLabel("<span style='font-size: 18pt;'>Energy</span>");
    labelEnergy->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelEnergykWhPerYear = new QLabel("<span style='font-size:9pt;'>Consumption <span style='font-size:7pt;'>(kWh/Year)</span></span>");
    QLabel *labelEnergyPricePerkWh = new QLabel("<span style='font-size:9pt;'>Price <span style='font-size:7pt;'>(c€/kWh)</span></span>");
    QLabel *labelEnergyBasePrice = new QLabel("<span style='font-size:9pt;'>Base Price <span style='font-size:7pt;'>(€/Month)</span></span>");

    QLineEdit *lineEnergykWhPerYear = new QLineEdit();
    QLineEdit *lineEnergyPricePerkWh = new QLineEdit();
    QLineEdit *lineEnergyBasePrice = new QLineEdit();


    QLabel *labelHeat = new QLabel("<span style='font-size: 18pt;'>Heat</span>");
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelHeatkWhPerYear = new QLabel("<span style='font-size:9pt;'>Consumption <span style='font-size:7pt;'>(kWh/Year)</span></span>");
    QLabel *labelHeatPricePerkWh = new QLabel("<span style='font-size:9pt;'>Price <span style='font-size:7pt;'>(c€/kWh)</span></span>");

    QLineEdit *lineHeatkWhPerYear = new QLineEdit();
    QLineEdit *lineHeatPricePerkWh = new QLineEdit();

    QLabel *labelFuel = new QLabel("<span style='font-size:9pt;'>Fuel:</span>");
    QRadioButton* radioGas = new QRadioButton("<span style='font-size:9pt;'>Gas</span>");
    QRadioButton* radioOil = new QRadioButton("<span style='font-size:9pt;'>Oil</span>");
    QCheckBox* checkHotWater = new QCheckBox("<span style='font-size:9pt;'>Hot Water included</span>");

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

    connect(lineEnergykWhPerYear,   SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_kWhPerYear(QString)));
    connect(lineEnergyPricePerkWh,  SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_pricePerkWh(QString)));
    connect(lineEnergyBasePrice,    SIGNAL(textEdited(QString)),    this, SLOT(setEnergy_basePrice(QString)));
    connect(lineHeatkWhPerYear,     SIGNAL(textEdited(QString)),    this, SLOT(setHeat_kWhPerYear(QString)));
    connect(lineHeatPricePerkWh,    SIGNAL(textEdited(QString)),    this, SLOT(setHeat_pricePerkWh(QString)));
    connect(radioGas,               SIGNAL(clicked()),              this, SLOT(checkGas()));
    connect(radioOil,               SIGNAL(clicked()),              this, SLOT(checkOil()));
    connect(checkHotWater,          SIGNAL(clicked(bool)),          this, SLOT(checkHotWater(bool)));
}

//Setters:

void ScreenHome1::setEnergy_kWhPerYear(QString _new)
{
    energy_kWhPerYear = _new;
}

void ScreenHome1::setEnergy_pricePerkWh(QString _new)
{
    energy_pricePerkWh = _new;
}

void ScreenHome1::setEnergy_basePrice(QString _new)
{
    energy_basePrice = _new;
}

void ScreenHome1::setHeat_kWhPerYear(QString _new)
{
    heat_kWhPerYear = _new;
}

void ScreenHome1::setHeat_pricePerkWh(QString _new)
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
    return energy_kWhPerYear.toInt();
}

double ScreenHome1::getEnergy_pricePerkWh()
{
    return energy_pricePerkWh.toDouble();
}

double ScreenHome1::getEnergy_basePrice()
{
    return energy_pricePerkWh.toDouble();
}

int ScreenHome1::getHeat_kWhPerYear()
{
    return heat_kWhPerYear.toInt();
}

double ScreenHome1::getHeat_pricePerkWh()
{
    return heat_pricePerkWh.toDouble();
}

bool ScreenHome1::getGasSelected()
{
    return gasSelected;
}

bool ScreenHome1::getWithHotWater()
{
    return withHotWater;
}
