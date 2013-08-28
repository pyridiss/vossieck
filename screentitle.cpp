#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

#include <iostream>

#include "screentitle.h"

ScreenTitle::ScreenTitle(QWidget *parent)
    : QWidget(parent)
{
    homeChecked = false;
    industryChecked = false;

    QLabel* text = new QLabel("<p><span style='font-weight:bold'>Introduction</span><br />\
                              This text introduces the program.</p>\
                              <p style='font-weight:bold;'>Please, choose a category:</p>");

    QRadioButton* radioIndustry =   new QRadioButton(tr("Industry"));
    QRadioButton* radioHome =       new QRadioButton(tr("Home"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(text);
    layout->addWidget(radioIndustry);
    layout->addWidget(radioHome);
    layout->setStretch(0, 0);
    layout->setStretch(1, 1);
    layout->setStretch(2, 1);
    setLayout(layout);

    connect(radioIndustry,  SIGNAL(clicked()), this, SLOT(checkIndustry()));
    connect(radioHome,      SIGNAL(clicked()), this, SLOT(checkHome()));
}

void ScreenTitle::checkIndustry()
{
    homeChecked = false;
    industryChecked = true;
}

void ScreenTitle::checkHome()
{
    homeChecked = true;
    industryChecked = false;
}
