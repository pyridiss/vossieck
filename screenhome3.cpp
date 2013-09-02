#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>

#include <iostream>

#include "screenhome3.h"

ScreenHome3::ScreenHome3(QWidget *parent)
    : QWidget(parent)
{
    mehrFamHausChecked = false;
    einFamHausChecked = false;
    wohnungChecked = false;
    eigentuemerChecked = false;
    mieteChecked = false;

    QLabel* labelHaus =  new QLabel("<span style='font-size:20pt;'>Wohnsituation</span>");
    QLabel* labelEigen = new QLabel("<span style='font-size:20pt;'>Eigentümer / Miete</span>");

    QRadioButton* radioMehrFamHaus =    new QRadioButton(tr("Mehrfamilienhaus"));
    QRadioButton* radioEinFamHaus =     new QRadioButton(tr("Einfamlienhaus"));
    QRadioButton* radioWohnung =        new QRadioButton(tr("Wohnung"));
    QRadioButton* radioEigentuemer =    new QRadioButton(tr("Eigentümer"));
    QRadioButton* radioMiete =          new QRadioButton(tr("Miete"));

    QGroupBox *groupHaus = new QGroupBox;
    QVBoxLayout *layoutHaus = new QVBoxLayout;
    layoutHaus->addWidget(labelHaus);
    layoutHaus->addWidget(radioMehrFamHaus);
    layoutHaus->addWidget(radioEinFamHaus);
    layoutHaus->addWidget(radioWohnung);
    groupHaus->setLayout(layoutHaus);

    QGroupBox *groupEigen = new QGroupBox;
    QVBoxLayout *layoutEigen = new QVBoxLayout;
    layoutEigen->addWidget(labelEigen);
    layoutEigen->addWidget(radioEigentuemer);
    layoutEigen->addWidget(radioMiete);
    groupEigen->setLayout(layoutEigen);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(groupHaus);
    layout->addWidget(groupEigen);
    setLayout(layout);

    connect(radioMehrFamHaus,   SIGNAL(clicked()), this, SLOT(setMehrFamHausChecked()));
    connect(radioEinFamHaus,    SIGNAL(clicked()), this, SLOT(setEinFamHausChecked()));
    connect(radioWohnung,       SIGNAL(clicked()), this, SLOT(setWohnungChecked()));
    connect(radioEigentuemer,   SIGNAL(clicked()), this, SLOT(setEigentuemerChecked()));
    connect(radioMiete,         SIGNAL(clicked()), this, SLOT(setMieteChecked()));
}

bool ScreenHome3::getMehrFamHausChecked()
{
    return mehrFamHausChecked;
}

bool ScreenHome3::getEinFamHausChecked()
{
    return einFamHausChecked;
}

bool ScreenHome3::getWohnungChecked()
{
    return wohnungChecked;
}

bool ScreenHome3::getEigentuemerChecked()
{
    return eigentuemerChecked;
}

bool ScreenHome3::getMieteChecked()
{
    return mieteChecked;
}

void ScreenHome3::setMehrFamHausChecked()
{
    mehrFamHausChecked = true;
    einFamHausChecked = false;
    wohnungChecked = false;
}

void ScreenHome3::setEinFamHausChecked()
{
    mehrFamHausChecked = false;
    einFamHausChecked = true;
    wohnungChecked = false;
}

void ScreenHome3::setWohnungChecked()
{
    mehrFamHausChecked = false;
    einFamHausChecked = false;
    wohnungChecked = true;
}

void ScreenHome3::setEigentuemerChecked()
{
    eigentuemerChecked = true;
    mieteChecked = false;
}

void ScreenHome3::setMieteChecked()
{
    eigentuemerChecked = false;
    mieteChecked = true;
}
