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
    mehrFamHaus = false;
    einFamHaus = false;
    wohnung = false;
    eigentuemer = false;
    miete = false;

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

    connect(radioMehrFamHaus,   SIGNAL(clicked()), this, SLOT(setMehrFamHaus()));
    connect(radioEinFamHaus,    SIGNAL(clicked()), this, SLOT(setEinFamHaus()));
    connect(radioWohnung,       SIGNAL(clicked()), this, SLOT(setWohnung()));
    connect(radioEigentuemer,   SIGNAL(clicked()), this, SLOT(setEigentuemer()));
    connect(radioMiete,         SIGNAL(clicked()), this, SLOT(setMiete()));
}

//Setters:

void HomeHabitat::setMehrFamHaus()
{
    mehrFamHaus = true;
    einFamHaus = false;
    wohnung = false;
}

void HomeHabitat::setEinFamHaus()
{
    mehrFamHaus = false;
    einFamHaus = true;
    wohnung = false;
}

void HomeHabitat::setWohnung()
{
    mehrFamHaus = false;
    einFamHaus = false;
    wohnung = true;
}

void HomeHabitat::setEigentuemer()
{
    eigentuemer = true;
    miete = false;
}

void HomeHabitat::setMiete()
{
    eigentuemer = false;
    miete = true;
}
