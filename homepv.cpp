#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>

#include "homepv.h"

HomePV::HomePV(QWidget *parent) :
    QWidget(parent)
{
    surface = 0;
    direction = "North";
    angle = 0;

    QLabel *labelPanels = new QLabel("<span style='font-size:20pt;'>Photovoltaic panels</span>");
    labelPanels->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelSurface = new QLabel("Roof surface");  labelSurface->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelDirection = new QLabel("Direction");   labelDirection->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelAngle = new QLabel("Angle");           labelAngle->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineSurface =    new QLineEdit();
    QLabel *unitSurface =       new QLabel("m²");

    QComboBox *lineDirection =  new QComboBox();

    QLineEdit *lineAngle =      new QLineEdit();
    QLabel* unitAngle =         new QLabel("°");

    lineDirection->addItem("North");
    lineDirection->addItem("North East");
    lineDirection->addItem("East");
    lineDirection->addItem("South East");
    lineDirection->addItem("South");
    lineDirection->addItem("South West");
    lineDirection->addItem("West");
    lineDirection->addItem("North West");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(labelPanels,      0, 0, 1, 3);
    layout->addWidget(labelSurface,     1, 0, 1, 1);
    layout->addWidget(labelDirection,   2, 0, 1, 1);
    layout->addWidget(labelAngle,       3, 0, 1, 1);
    layout->addWidget(lineSurface,      1, 1, 1, 1);
    layout->addWidget(lineDirection,    2, 1, 1, 1);
    layout->addWidget(lineAngle,        3, 1, 1, 1);
    layout->addWidget(unitSurface,      1, 2, 1, 1);
    layout->addWidget(unitAngle,        3, 2, 1, 1);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 2);
    layout->setColumnStretch(2, 1);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(4, 1);
    setLayout(layout);

    connect(lineSurface,    SIGNAL(textEdited(QString)),            this, SLOT(setSurface(QString)));
    connect(lineDirection,  SIGNAL(currentIndexChanged(QString)),   this, SLOT(setDirection(QString)));
    connect(lineAngle,      SIGNAL(textEdited(QString)),            this, SLOT(setAngle(QString)));

    //Signals to stop editing fields
    connect(lineSurface,    SIGNAL(returnPressed()),    this, SLOT(setFocus()));
    connect(lineAngle,      SIGNAL(returnPressed()),    this, SLOT(setFocus()));
}

//Setters:

void HomePV::setSurface(QString _new)
{
    surface = _new.toInt();
}

void HomePV::setDirection(QString _new)
{
    direction = _new;
}

void HomePV::setAngle(QString _new)
{
    angle = _new.toInt();
}
