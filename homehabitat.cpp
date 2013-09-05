#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>

#include <iostream>

#include "homehabitat.h"

HomeHabitat::HomeHabitat(QWidget *parent)
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
    layoutHaus->addStretch(1);
    groupHaus->setLayout(layoutHaus);

    QGroupBox *groupEigen = new QGroupBox;
    QVBoxLayout *layoutEigen = new QVBoxLayout;
    layoutEigen->addWidget(labelEigen);
    layoutEigen->addWidget(radioEigentuemer);
    layoutEigen->addWidget(radioMiete);
    layoutEigen->addStretch(1);
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

//Setters:

void HomeHabitat::setMehrFamHausChecked()
{
    mehrFamHausChecked = true;
    einFamHausChecked = false;
    wohnungChecked = false;
}

void HomeHabitat::setEinFamHausChecked()
{
    mehrFamHausChecked = false;
    einFamHausChecked = true;
    wohnungChecked = false;
}

void HomeHabitat::setWohnungChecked()
{
    mehrFamHausChecked = false;
    einFamHausChecked = false;
    wohnungChecked = true;
}

void HomeHabitat::setEigentuemerChecked()
{
    eigentuemerChecked = true;
    mieteChecked = false;
}

void HomeHabitat::setMieteChecked()
{
    eigentuemerChecked = false;
    mieteChecked = true;
}
