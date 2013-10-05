#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>

#include "homeheat.h"

HomeHeat::HomeHeat(QWidget *parent) :
    QWidget(parent)
{
    heat_consumption = 0;
    heat_price = 0;
    gas = false;
    oil = false;
    hotWater = false;

    QLabel *labelHeat = new QLabel(tr("<span style='font-size: 20pt;'>Heat</span>"));
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelHeatConsumption = new QLabel(tr("Consumption"));   labelHeatConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelHeatPrice       = new QLabel(tr("Price"));         labelHeatPrice->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineHeatConsumption  = new QLineEdit();
    QLabel *unitHeatConsumption     = new QLabel(tr("kWh/year"));

    QLineEdit *lineHeatPrice        = new QLineEdit();
    QLabel *unitHeatPrice           = new QLabel(tr("c€/kWh"));

    QLabel *labelFuel = new QLabel(tr("Fuel:"));                    labelFuel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QRadioButton* radioGas       = new QRadioButton(tr("Gas"));
    QRadioButton* radioOil       = new QRadioButton(tr("Oil"));
    QRadioButton* radioOtherMean = new QRadioButton(tr("Other mean:"));
    QLineEdit* lineOtherMean     = new QLineEdit();
    QCheckBox* checkHotWater     = new QCheckBox(tr("Hot Water included"));

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelHeat,                0, 0, 1, 4);
    layout->addWidget(labelHeatConsumption,     1, 0, 1, 1);
    layout->addWidget(labelHeatPrice,           2, 0, 1, 1);
    layout->addWidget(lineHeatConsumption,      1, 1, 1, 2);
    layout->addWidget(lineHeatPrice,            2, 1, 1, 2);
    layout->addWidget(unitHeatConsumption,      1, 3, 1, 1);
    layout->addWidget(unitHeatPrice,            2, 3, 1, 1);
    layout->addWidget(labelFuel,                3, 0, 2, 1);
    layout->addWidget(radioGas,                 3, 1, 1, 1);
    layout->addWidget(radioOil,                 3, 2, 1, 1);
    layout->addWidget(radioOtherMean,           4, 1, 1, 1);
    layout->addWidget(lineOtherMean,            4, 2, 1, 1);
    layout->addWidget(checkHotWater,            5, 1, 1, 2);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(6, 1);
    layout->setColumnStretch(0, 2);
    layout->setColumnStretch(1, 1);
    layout->setColumnStretch(2, 3);
    layout->setColumnStretch(3, 2);
    setLayout(layout);

    connect(lineHeatConsumption,    SIGNAL(textEdited(QString)),    this, SLOT(setHeat_consumption(QString)));
    connect(lineHeatPrice,          SIGNAL(textEdited(QString)),    this, SLOT(setHeat_price(QString)));
    connect(radioGas,               SIGNAL(clicked()),              this, SLOT(setGas()));
    connect(radioOil,               SIGNAL(clicked()),              this, SLOT(setOil()));
    connect(radioOtherMean,         SIGNAL(clicked()),              this, SLOT(setOtherMean()));
    connect(lineOtherMean,          SIGNAL(textEdited(QString)),    this, SLOT(setOtherMean()));
    connect(checkHotWater,          SIGNAL(clicked(bool)),          this, SLOT(setHotWater(bool)));

    //Signals to stop editing fields
    connect(lineHeatConsumption,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineHeatPrice,          SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineOtherMean,          SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}

//Setters:

void HomeHeat::setHeat_consumption(QString _new)
{
    heat_consumption = _new.toInt();
}

void HomeHeat::setHeat_price(QString _new)
{
    heat_price = _new.toDouble();
}

void HomeHeat::setGas()
{
    gas = true;
    oil = false;
}

void HomeHeat::setOil()
{
    gas = false;
    oil = true;
}

void HomeHeat::setHotWater(bool _new)
{
    hotWater = _new;
}

void HomeHeat::setOtherMean()
{
    gas = false;
    oil = false;
}

void HomeHeat::setProductionMean(QString _new)
{
    productionMean = _new;
}
