#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include <iostream>

#include "screentitle.h"

ScreenTitle::ScreenTitle(QWidget *parent)
    : QWidget(parent)
{
    home = false;
    industry = false;

    QLabel* text = new QLabel("<p><span style='font-weight:bold'>Introduction</span><br />\
                              This text introduces the program.</p>\
                              <p style='font-weight:bold;'>Please, choose a category:</p>");

    QRadioButton* radioIndustry =   new QRadioButton(tr("Industry"));
    QRadioButton* radioHome =       new QRadioButton(tr("Private user"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(text);
    layout->addWidget(radioIndustry);
    layout->addWidget(radioHome);
    layout->setStretch(0, 0);
    layout->setStretch(1, 1);
    layout->setStretch(2, 1);
    setLayout(layout);

    connect(radioIndustry,  SIGNAL(clicked()), this, SLOT(setIndustry()));
    connect(radioHome,      SIGNAL(clicked()), this, SLOT(setHome()));
}

void ScreenTitle::setIndustry()
{
    home = false;
    industry = true;
}

void ScreenTitle::setHome()
{
    home = true;
    industry = false;
}
