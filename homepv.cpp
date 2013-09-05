#include <QLabel>
#include <QGridLayout>
#include <QSpinBox>
#include <QComboBox>

#include "homepv.h"

HomePV::HomePV(QWidget *parent) :
    QWidget(parent)
{
    surface = 0;
    angle = 0;

    QLabel *labelPanels = new QLabel("<span style='font-size:20pt;'>Photovoltaic panels</span>");
    labelPanels->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelSurface = new QLabel("Roof surface");
    QLabel *labelDirection = new QLabel("Direction");
    QLabel *labelAngle = new QLabel("Angle");

    QSpinBox *lineSurface =     new QSpinBox();
    lineSurface->setRange(0, 1000);   lineSurface->setSingleStep(1);
    lineSurface->setAccelerated(true);
    lineSurface->setSuffix(" m²");

    QComboBox *lineDirection =  new QComboBox();

    QSpinBox *lineAngle =       new QSpinBox();
    lineAngle->setRange(0, 50);     lineAngle->setSingleStep(1);
    lineAngle->setAccelerated(true);
    lineAngle->setSuffix(" °");

    lineDirection->addItem("North");
    lineDirection->addItem("North East");
    lineDirection->addItem("East");
    lineDirection->addItem("South East");
    lineDirection->addItem("South");
    lineDirection->addItem("South West");
    lineDirection->addItem("West");
    lineDirection->addItem("North West");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelPanels, 0, 0, 1, 2);
    layout->addWidget(labelSurface, 1, 0, 1, 1);
    layout->addWidget(labelDirection, 2, 0, 1, 1);
    layout->addWidget(labelAngle, 3, 0, 1, 1);
    layout->addWidget(lineSurface, 1, 1, 1, 1);
    layout->addWidget(lineDirection, 2, 1, 1, 1);
    layout->addWidget(lineAngle, 3, 1, 1, 1);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    setLayout(layout);

    connect(lineSurface,    SIGNAL(valueChanged(int)),              this, SLOT(setSurface(int)));
    connect(lineDirection,  SIGNAL(currentIndexChanged(QString)),   this, SLOT(setDirection(QString)));
    connect(lineAngle,      SIGNAL(valueChanged(int)),              this, SLOT(setAngle(int)));

    //Signals to stop editing fields
    connect(lineSurface,    SIGNAL(editingFinished()),              this, SLOT(setFocus()));
    connect(lineAngle,      SIGNAL(editingFinished()),              this, SLOT(setFocus()));
}

//Setters:

void HomePV::setSurface(int _new)
{
    surface = _new;
}

void HomePV::setDirection(QString _new)
{
    direction = _new;
}

void HomePV::setAngle(int _new)
{
    angle = _new;
}
