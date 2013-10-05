#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "industryheat.h"

IndustryHeat::IndustryHeat(QWidget *parent) :
    QWidget(parent)
{
    consumption = 0;
    price = 0;
    gas = false;
    oil = false;

    QLabel *labelHeat = new QLabel("<span style='font-size: 20pt;'>Heat</span>");
    labelHeat->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelConsumption = new QLabel("Consumption");   labelConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelPrice       = new QLabel("Price");         labelPrice->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineConsumption  = new QLineEdit();
    QLabel *unitConsumption     = new QLabel("kWh/year");

    QLineEdit *linePrice        = new QLineEdit();
    QLabel *unitPrice           = new QLabel("c€/kWh");

    QLabel *labelFuel = new QLabel("Fuel:");                    labelFuel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QRadioButton* radioGas       = new QRadioButton("Gas");
    QRadioButton* radioOil       = new QRadioButton("Oil");
    QRadioButton* radioOtherMean = new QRadioButton("Other mean:");
    QLineEdit* lineOtherMean     = new QLineEdit();

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelHeat,            0, 0, 1, 4);
    layout->addWidget(labelConsumption,     1, 0, 1, 1);
    layout->addWidget(labelPrice,           2, 0, 1, 1);
    layout->addWidget(lineConsumption,      1, 1, 1, 2);
    layout->addWidget(linePrice,            2, 1, 1, 2);
    layout->addWidget(unitConsumption,      1, 3, 1, 1);
    layout->addWidget(unitPrice,            2, 3, 1, 1);
    layout->addWidget(labelFuel,            3, 0, 2, 1);
    layout->addWidget(radioGas,             3, 1, 1, 1);
    layout->addWidget(radioOil,             3, 2, 1, 1);
    layout->addWidget(radioOtherMean,       4, 1, 1, 1);
    layout->addWidget(lineOtherMean,        4, 2, 1, 1);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(5, 1);
    layout->setColumnStretch(0, 2);
    layout->setColumnStretch(1, 1);
    layout->setColumnStretch(2, 3);
    layout->setColumnStretch(3, 2);
    setLayout(layout);

    connect(lineConsumption,    SIGNAL(textEdited(QString)),    this, SLOT(setConsumption(QString)));
    connect(linePrice,          SIGNAL(textEdited(QString)),    this, SLOT(setPrice(QString)));
    connect(radioGas,           SIGNAL(clicked()),              this, SLOT(setGas()));
    connect(radioOil,           SIGNAL(clicked()),              this, SLOT(setOil()));
    connect(radioOtherMean,     SIGNAL(clicked()),              this, SLOT(setOtherMean()));
    connect(lineOtherMean,      SIGNAL(textEdited(QString)),    this, SLOT(setOtherMean()));

    //Signals to stop editing fields
    connect(lineConsumption,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(linePrice,          SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineOtherMean,      SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}

//Setters:

void IndustryHeat::setConsumption(QString _new)
{
    consumption = _new.toInt();
}

void IndustryHeat::setPrice(QString _new)
{
    price = _new.toDouble();
}

void IndustryHeat::setGas()
{
    gas = true;
    oil = false;
}

void IndustryHeat::setOil()
{
    gas = false;
    oil = true;
}

void IndustryHeat::setOtherMean()
{
    gas = false;
    oil = false;
}

void IndustryHeat::setProductionMean(QString _new)
{
    productionMean = _new;
}
