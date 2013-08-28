#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QComboBox>

#include "screenhome2.h"

ScreenHome2::ScreenHome2(QWidget *parent) :
    QWidget(parent)
{
    QLabel *labelPanels = new QLabel("<span style='font-size:20pt;'>Photovoltaic panels</span>");
    labelPanels->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelSurface = new QLabel("Roof surface <span style='font-size:10pt;'>(m²)</span></span>");
    QLabel *labelDirection = new QLabel("Direction");
    QLabel *labelAngle = new QLabel("Angle <span style='font-size:10pt;'>(°)</span></span>");

    QSpinBox *lineSurface =     new QSpinBox();
    lineSurface->setRange(1000, 1000000);   lineSurface->setSingleStep(500);
    QComboBox *lineDirection =  new QComboBox();
    QSpinBox *lineAngle =       new QSpinBox();
    lineAngle->setRange(1000, 1000000);     lineAngle->setSingleStep(500);

    lineDirection->addItem("North");
    lineDirection->addItem("North East");
    lineDirection->addItem("East");
    lineDirection->addItem("South East");
    lineDirection->addItem("South");
    lineDirection->addItem("North West");
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
}

//Getters:

int     ScreenHome2::getSurface()
{
    return surface;
}

QString ScreenHome2::getDirection()
{
    return direction;
}

int     ScreenHome2::getAngle()
{
    return angle;
}

//Setters:

void ScreenHome2::setSurface(int _new)
{
    surface = _new;
}

void ScreenHome2::setDirection(QString _new)
{
    direction = _new;
}

void ScreenHome2::setAngle(int _new)
{
    angle = _new;
}
