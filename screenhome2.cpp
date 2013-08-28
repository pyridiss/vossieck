#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "screenhome2.h"

ScreenHome2::ScreenHome2(QWidget *parent) :
    QWidget(parent)
{
    QLabel *labelPanels = new QLabel("<span style='font-size: 18pt;'>Photovoltaic panels</span>");
    labelPanels->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    QLabel *labelSurface = new QLabel("<span style='font-size:9pt;'>Roof surface <span style='font-size:7pt;'>(m²)</span></span>");
    QLabel *labelDirection = new QLabel("<span style='font-size:9pt;'>Direction</span>");
    QLabel *labelAngle = new QLabel("<span style='font-size:9pt;'>Angle <span style='font-size:7pt;'>(°)</span></span>");

    QLineEdit *lineSurface = new QLineEdit();
    QLineEdit *lineDirection = new QLineEdit();
    QLineEdit *lineAngle = new QLineEdit();


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

    connect(lineSurface,    SIGNAL(textEdited(QString)),    this, SLOT(setSurface(QString)));
    connect(lineDirection,  SIGNAL(textEdited(QString)),    this, SLOT(setDirection(QString)));
    connect(lineAngle,      SIGNAL(textEdited(QString)),    this, SLOT(setAngle(QString)));
}

//Getters:

double  ScreenHome2::getSurface()
{
    return surface.toDouble();
}

QString ScreenHome2::getDirection()
{
    return direction;
}

int     ScreenHome2::getAngle()
{
    return angle.toInt();
}

//Setters:

void ScreenHome2::setSurface(QString _new)
{
    surface = _new;
}

void ScreenHome2::setDirection(QString _new)
{
    direction = _new;
}

void ScreenHome2::setAngle(QString _new)
{
    angle = _new;
}
