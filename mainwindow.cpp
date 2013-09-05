#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>

#include "mainwindow.h"

//Defined in main.cpp
int getScreenWidth();
int getScreenHeight();
QString toStr(int);
QString toStr(double);

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    currentScreen = "title";

    //Application Logo
    QLabel *title = new QLabel;
    title->setAlignment(Qt::AlignHCenter);
    title->setPixmap(loadLogo());
    title->setScaledContents(true);

    //Screens
    screenTitle = new ScreenTitle(this);
    industryConsumption = new IndustryConsumption(this);    industryConsumption->hide();
    screenIndustry2 = new ScreenIndustry2(this);            screenIndustry2->hide();
    homeConsumption = new HomeConsumption(this);            homeConsumption->hide();
    homePV = new HomePV(this);                              homePV->hide();
    homeHabitat = new HomeHabitat(this);                    homeHabitat->hide();
    finalScreen = new FinalScreen(this);                    finalScreen->hide();

    //Previous & Next
    prev = new QPushButton("Quit");
    next = new QPushButton("Next >");

    //Grid Layout
    layoutMainWindow.addWidget(title, 0, 0, 1, 2);
    layoutMainWindow.addWidget(screenTitle, 1, 0, 1, 2);
    layoutMainWindow.addWidget(industryConsumption, 1, 0, 1, 2);
    layoutMainWindow.addWidget(screenIndustry2, 1, 0, 1, 2);
    layoutMainWindow.addWidget(homeConsumption, 1, 0, 1, 2);
    layoutMainWindow.addWidget(homePV, 1, 0, 1, 2);
    layoutMainWindow.addWidget(homeHabitat, 1, 0, 1, 2);
    layoutMainWindow.addWidget(finalScreen, 1, 0, 1, 2);
    layoutMainWindow.addWidget(prev, 2, 0, 1, 1);
    layoutMainWindow.addWidget(next, 2, 1, 1, 1);
    layoutMainWindow.setRowStretch(0, 0);
    layoutMainWindow.setRowStretch(1, 1);
    layoutMainWindow.setRowStretch(2, 0);
    setLayout(&layoutMainWindow);

    connect(prev, SIGNAL(clicked()), this, SLOT(previousScreen()));
    connect(next, SIGNAL(clicked()), this, SLOT(nextScreen()));
}

QPixmap& MainWindow::loadLogo()
{
    QPixmap* logoOriginal = new QPixmap(":/logo.jpg");
    int logoWidth = logoOriginal->width();

    if (logoWidth > getScreenWidth() - 30)
    {
        QPixmap* logoScaled = new QPixmap();

        *logoScaled = logoOriginal->scaled(getScreenWidth() - 30, getScreenHeight(), Qt::KeepAspectRatio);
        return *logoScaled;
    }
    else return *logoOriginal;
}

void MainWindow::changeScreen(string _newTitle, QWidget* _oldScreen, QWidget* _newScreen)
{
    currentScreen = _newTitle;
    layoutMainWindow.removeWidget(_oldScreen);
    layoutMainWindow.addWidget(_newScreen, 1, 0, 1, 2);
    _oldScreen->hide();
    _newScreen->show();
}

void MainWindow::previousScreen()
{
    if (currentScreen == "title")
    {
        qApp->quit();
    }
    else if (currentScreen == "industryConsumption")
    {
        changeScreen("title", industryConsumption, screenTitle);
        prev->setText("Quit");
    }
    else if (currentScreen == "homeHabitat")
    {
        changeScreen("title", homeHabitat, screenTitle);
        prev->setText("Quit");
    }
    else if (currentScreen == "industry2")
        changeScreen("industryConsumption", screenIndustry2, industryConsumption);

    else if (currentScreen == "homeConsumption")
        changeScreen("homeHabitat", homeConsumption, homeHabitat);

    else if (currentScreen == "homePV")
        changeScreen("homeConsumption", homePV, homeConsumption);

    else if (currentScreen == "final")
    {
        if (screenTitle->industryChecked)   changeScreen("industry2", finalScreen, screenIndustry2);
        if (screenTitle->homeChecked)       changeScreen("homePV", finalScreen, homePV);
        next->setText("Next >");
    }
}

void MainWindow::nextScreen()
{
    if (currentScreen == "title" && screenTitle->homeChecked)
    {
        changeScreen("homeHabitat", screenTitle, homeHabitat);
        prev->setText("< Previous");
    }
    else if (currentScreen == "title" && screenTitle->industryChecked)
    {
        changeScreen("industryConsumption", screenTitle, industryConsumption);
        prev->setText("< Previous");
    }
    else if (currentScreen == "industryConsumption")
        changeScreen("industry2", industryConsumption, screenIndustry2);

    else if (currentScreen == "homeHabitat")
        changeScreen("homeConsumption", homeHabitat, homeConsumption);

    else if (currentScreen == "homeConsumption")
        changeScreen("homePV", homeConsumption, homePV);

    else if (currentScreen == "industry2" || currentScreen == "homePV")
    {
        if (currentScreen == "industry2")   changeScreen("final", screenIndustry2, finalScreen);
        if (currentScreen == "homePV")      changeScreen("final", homePV, finalScreen);
        createDataString();
        next->setText("Quit");
    }
    else if (currentScreen == "final")
    {
        qApp->quit();
    }
}

void MainWindow::createDataString()
{
    QString str = "";

    //Screen Title
    if (screenTitle->homeChecked) str += "profile=Home";
    if (screenTitle->industryChecked) str += "profile=Industry";
    str += "&";

    //Screen Home Consumption
    str += "sh1-en_cons=";      str += toStr(homeConsumption->energy_consumption);          str += "&";
    str += "sh1-en_price=";     str += toStr(homeConsumption->energy_price);                str += "&";
    str += "sh1-en_bprice=";    str += toStr(homeConsumption->energy_basePrice);            str += "&";
    str += "sh1-he_cons=";      str += toStr(homeConsumption->heat_consumption);            str += "&";
    str += "sh1-he_price=";     str += toStr(homeConsumption->heat_price);                  str += "&";
    str += "sh1-gas=";          str += (homeConsumption->gasSelected) ? "true" : "false";   str += "&";
    str += "sh1-hotwater=";     str += (homeConsumption->withHotWater) ? "true" : "false";  str += "&";

    //Screen Home PV
    str += "sh2-surf=";     str += toStr(homePV->surface);    str += "&";
    str += "sh2-dir=";      str += homePV->direction;  str += "&";
    str += "sh2-angle=";    str += toStr(homePV->angle);      str += "&";

    //Screen Home Habitat
    str += "sh3-mehr=";     str += (homeHabitat->mehrFamHausChecked) ? "true" : "false";    str += "&";
    str += "sh3-ein=";      str += (homeHabitat->einFamHausChecked) ? "true" : "false";     str += "&";
    str += "sh3-wohn=";     str += (homeHabitat->wohnungChecked) ? "true" : "false";        str += "&";
    str += "sh3-eigen=";    str += (homeHabitat->eigentuemerChecked) ? "true" : "false";    str += "&";
    str += "sh3-miete=";    str += (homeHabitat->mieteChecked) ? "true" : "false";          str += "&";

    //Screen Industry Consumption
    str += "si1-cons=";     str += toStr(industryConsumption->consumption);                 str += "&";
    str += "si1-htap=";     str += toStr(industryConsumption->hTArbPreis);                  str += "&";
    str += "si1-ntap=";     str += toStr(industryConsumption->nTArbPreis);                  str += "&";
    str += "si1-netz=";     str += toStr(industryConsumption->netzkosten);                  str += "&";
    str += "si1-eeg=";      str += (industryConsumption->checkedEEG) ? "true" : "false";    str += "&";
    str += "si1-kwk=";      str += toStr(industryConsumption->kWK);                         str += "&";
    str += "si1-strsmg=";   str += toStr(industryConsumption->stromstG);                    str += "&";
    str += "si1-off=";      str += toStr(industryConsumption->offshore);                    str += "&";
    str += "si1-leist=";    str += toStr(industryConsumption->leistung);                    str += "&";

    //Screen Industry 2

    //Sending data string
    int valeur = 55;
    str += "valeur=";   str += valeur;
    finalScreen->setDataString(str);
}
