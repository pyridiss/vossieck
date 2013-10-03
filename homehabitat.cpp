#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>

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

    QLabel* labelHaus    = new QLabel("<span style='font-size:20pt;'>Wohnsituation</span>");
    QLabel* labelEigen   = new QLabel("<span style='font-size:20pt;'>Eigentümer / Miete</span>");

    QRadioButton* radioMehrFamHaus =    new QRadioButton("Mehrfamilienhaus");
    QRadioButton* radioEinFamHaus =     new QRadioButton("Einfamlienhaus");
    QRadioButton* radioWohnung =        new QRadioButton("Wohnung");
    QRadioButton* radioEigentuemer =    new QRadioButton("Eigentümer");
    QRadioButton* radioMiete =          new QRadioButton("Miete");

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

    QLabel* labelSurface   = new QLabel("Floor surface:"); labelSurface->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLineEdit *lineSurface = new QLineEdit();
    QLabel *unitSurface    = new QLabel("m²");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(groupHaus,    0, 0, 1, 3);
    layout->addWidget(groupEigen,   1, 0, 1, 3);
    layout->addWidget(labelSurface, 2, 0, 1, 1);
    layout->addWidget(lineSurface,  2, 1, 1, 1);
    layout->addWidget(unitSurface,  2, 2, 1, 1);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 2);
    layout->setColumnStretch(2, 1);

    setLayout(layout);

    connect(radioMehrFamHaus,   SIGNAL(clicked()), this, SLOT(setMehrFamHaus()));
    connect(radioEinFamHaus,    SIGNAL(clicked()), this, SLOT(setEinFamHaus()));
    connect(radioWohnung,       SIGNAL(clicked()), this, SLOT(setWohnung()));
    connect(radioEigentuemer,   SIGNAL(clicked()), this, SLOT(setEigentuemer()));
    connect(radioMiete,         SIGNAL(clicked()), this, SLOT(setMiete()));

    connect(lineSurface, SIGNAL(textEdited(QString)),   this, SLOT(setSurface(QString)));
    connect(lineSurface, SIGNAL(returnPressed()),       this, SLOT(setFocus()));
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

void HomeHabitat::setSurface(QString _new)
{
    surface = _new.toInt();
}
