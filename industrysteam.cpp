#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>

#include "industrysteam.h"

IndustrySteam::IndustrySteam(QWidget *parent) :
    QWidget(parent)
{
    steam = false;
    pressure = 0;
    consumption = 0;
    temperature = 0;
    gas = false;
    oil = false;

    QLabel *labelSteam = new QLabel("<span style='font-size: 20pt;'>Steam</span>");
    labelSteam->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelQuestion = new QLabel("Does your production process use steam?");
    QRadioButton *radioSteamYes = new QRadioButton("Yes");
    QRadioButton *radioSteamNo  = new QRadioButton("No");

    QGroupBox *groupQuestion    = new QGroupBox;
    QHBoxLayout *layoutQuestion = new QHBoxLayout;
    layoutQuestion->addWidget(labelQuestion, 2);
    layoutQuestion->addWidget(radioSteamYes, 1);
    layoutQuestion->addWidget(radioSteamNo,  1);
    groupQuestion->setLayout(layoutQuestion);

    QLabel *labelPressure       = new QLabel("Pressure");       labelPressure->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelConsumption    = new QLabel("Consumption");    labelConsumption->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelTemperature    = new QLabel("Price");          labelTemperature->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *linePressure     = new QLineEdit();
    QLabel *unitPressure        = new QLabel("bars");

    QLineEdit *lineConsumption  = new QLineEdit();
    QLabel *unitConsumption     = new QLabel("kWh/year");

    QLineEdit *lineTemperature  = new QLineEdit();
    QLabel *unitTemperature     = new QLabel("°C");

    QLabel *labelFuel = new QLabel("Fuel:");                    labelFuel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QRadioButton* radioGas       = new QRadioButton("Gas");
    QRadioButton* radioOil       = new QRadioButton("Oil");
    QRadioButton* radioOtherMean = new QRadioButton("Other mean:");
    QLineEdit* lineOtherMean     = new QLineEdit();

    QGroupBox *groupYes = new QGroupBox;
    groupYes->setTitle("If yes, please fill this form:");
    QGridLayout *layoutYes = new QGridLayout;
    layoutYes->addWidget(labelPressure,         0, 0, 1, 1);
    layoutYes->addWidget(labelConsumption,      1, 0, 1, 1);
    layoutYes->addWidget(labelTemperature,      2, 0, 1, 1);
    layoutYes->addWidget(linePressure,          0, 1, 1, 2);
    layoutYes->addWidget(lineConsumption,       1, 1, 1, 2);
    layoutYes->addWidget(lineTemperature,       2, 1, 1, 2);
    layoutYes->addWidget(unitPressure,          0, 3, 1, 1);
    layoutYes->addWidget(unitConsumption,       1, 3, 1, 1);
    layoutYes->addWidget(unitTemperature,       2, 3, 1, 1);
    layoutYes->addWidget(labelFuel,             3, 0, 2, 1);
    layoutYes->addWidget(radioGas,              3, 1, 1, 1);
    layoutYes->addWidget(radioOil,              3, 2, 1, 1);
    layoutYes->addWidget(radioOtherMean,        4, 1, 1, 1);
    layoutYes->addWidget(lineOtherMean,         4, 2, 1, 1);
    layoutYes->setColumnStretch(0, 2);
    layoutYes->setColumnStretch(1, 1);
    layoutYes->setColumnStretch(2, 3);
    layoutYes->setColumnStretch(3, 2);
    groupYes->setLayout(layoutYes);

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(labelSteam);
    layout->addWidget(groupQuestion);
    layout->addWidget(groupYes);

    layout->setStretch(0, 1);
    layout->setStretch(2, 1);
    setLayout(layout);

    connect(radioSteamYes,      SIGNAL(clicked()),              this, SLOT(setSteamYes()));
    connect(radioSteamNo,       SIGNAL(clicked()),              this, SLOT(setSteamNo()));
    connect(linePressure,       SIGNAL(textEdited(QString)),    this, SLOT(setPressure(QString)));
    connect(lineConsumption,    SIGNAL(textEdited(QString)),    this, SLOT(setConsumption(QString)));
    connect(lineTemperature,    SIGNAL(textEdited(QString)),    this, SLOT(setTemperature(QString)));
    connect(radioGas,           SIGNAL(clicked()),              this, SLOT(setGas()));
    connect(radioOil,           SIGNAL(clicked()),              this, SLOT(setOil()));
    connect(radioOtherMean,     SIGNAL(clicked()),              this, SLOT(setOtherMean()));
    connect(lineOtherMean,      SIGNAL(textEdited(QString)),    this, SLOT(setOtherMean()));

    //Signals to stop editing fields
    connect(linePressure,       SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineConsumption,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineTemperature,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineOtherMean,      SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}


//Setters:

void IndustrySteam::setSteamYes()
{
    steam = true;
}

void IndustrySteam::setSteamNo()
{
    steam = false;
}

void IndustrySteam::setPressure(QString _new)
{
    pressure = _new.toDouble();
}

void IndustrySteam::setConsumption(QString _new)
{
    consumption = _new.toInt();
}

void IndustrySteam::setTemperature(QString _new)
{
    temperature = _new.toInt();
}

void IndustrySteam::setGas()
{
    gas = true;
    oil = false;
}

void IndustrySteam::setOil()
{
    gas = false;
    oil = true;
}

void IndustrySteam::setOtherMean()
{
    gas = false;
    oil = false;
}

void IndustrySteam::setProductionMean(QString _new)
{
    productionMean = _new;
}
