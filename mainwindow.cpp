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
    dataSent = false;

    //Application Logo
    QLabel *title = new QLabel;
    title->setAlignment(Qt::AlignHCenter);
    title->setPixmap(loadLogo());
    title->setScaledContents(true);

    //Screens
    screenTitle         = new ScreenTitle(this);
    industryElectricity = new IndustryElectricity(this);    industryElectricity->hide();
    industryHeat        = new IndustryHeat(this);           industryHeat->hide();
    industrySteam       = new IndustrySteam(this);          industrySteam->hide();
    homeElectricity     = new HomeElectricity(this);        homeElectricity->hide();
    homeHeat            = new HomeHeat(this);               homeHeat->hide();
    homePV              = new HomePV(this);                 homePV->hide();
    homeHabitat         = new HomeHabitat(this);            homeHabitat->hide();
    finalScreen         = new FinalScreen(this);            finalScreen->hide();

    //Previous & Next
    prev = new QPushButton(tr("Quit"));
    next = new QPushButton(tr("Next >"));

    //Grid Layout
    layoutMainWindow.addWidget(title,               0, 0, 1, 2);
    layoutMainWindow.addWidget(screenTitle,         1, 0, 1, 2);
    layoutMainWindow.addWidget(industryElectricity, 1, 0, 1, 2);
    layoutMainWindow.addWidget(industryHeat,        1, 0, 1, 2);
    layoutMainWindow.addWidget(industrySteam  ,     1, 0, 1, 2);
    layoutMainWindow.addWidget(homeElectricity,     1, 0, 1, 2);
    layoutMainWindow.addWidget(homeHeat,            1, 0, 1, 2);
    layoutMainWindow.addWidget(homePV,              1, 0, 1, 2);
    layoutMainWindow.addWidget(homeHabitat,         1, 0, 1, 2);
    layoutMainWindow.addWidget(finalScreen,         1, 0, 1, 2);
    layoutMainWindow.addWidget(prev,                2, 0, 1, 1);
    layoutMainWindow.addWidget(next,                2, 1, 1, 1);
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

    //HOME BRANCH
    else if (currentScreen == "homeElectricity")
    {
        changeScreen("title", homeElectricity, screenTitle);
        prev->setText(tr("Quit"));
    }
    else if (currentScreen == "homeHeat")
    {
        changeScreen("homeElectricity", homeHeat, homeElectricity);
    }
    else if (currentScreen == "homeHabitat")
    {
        changeScreen("homeHeat", homeHabitat, homeHeat);
    }
    else if (currentScreen == "homePV")
    {
        changeScreen("homeHabitat", homePV, homeHabitat);
    }
    else if (currentScreen == "final" && screenTitle->home)
    {
        if (homeHabitat->einFamHaus && homeHabitat->eigentuemer)
            changeScreen("homePV", finalScreen, homePV);
        else
            changeScreen("homeHabitat", finalScreen, homeHabitat);
        next->setText(tr("Next >"));
    }

    //INDUSTRY BRANCH
    else if (currentScreen == "industryElectricity")
    {
        changeScreen("title", industryElectricity, screenTitle);
        prev->setText(tr("Quit"));
    }
    else if (currentScreen == "industryHeat")
    {
        changeScreen("industryElectricity", industryHeat, industryElectricity);
    }
    else if (currentScreen == "industrySteam")
    {
        changeScreen("industryHeat", industrySteam, industryHeat);
    }
    else if (currentScreen == "final" && screenTitle->industry)
    {
        changeScreen("industrySteam", finalScreen, industrySteam);
        next->setText(tr("Next >"));
    }
}

void MainWindow::nextScreen()
{
    // HOME BRANCH
    if (currentScreen == "title" && screenTitle->home)
    {
        changeScreen("homeElectricity", screenTitle, homeElectricity);
        prev->setText(tr("< Previous"));
    }
    else if (currentScreen == "homeElectricity")
    {
        changeScreen("homeHeat", homeElectricity, homeHeat);
    }
    else if (currentScreen == "homeHeat")
    {
        changeScreen("homeHabitat", homeHeat, homeHabitat);
    }
    else if (currentScreen == "homeHabitat")
    {
        if (homeHabitat->einFamHaus && homeHabitat->eigentuemer)
            changeScreen("homePV", homeHabitat, homePV);
        else if ((homeHabitat->mehrFamHaus || homeHabitat->einFamHaus || homeHabitat->wohnung) &&
                 (homeHabitat->eigentuemer || homeHabitat->miete)
                )
        {
            changeScreen("final", homeHabitat, finalScreen);
            next->setText(tr("Send data"));
        }
    }
    else if (currentScreen == "homePV")
    {
        changeScreen("final", homePV, finalScreen);
        next->setText(tr("Send data"));
    }

    //INDUSTRY BRANCH
    else if (currentScreen == "title" && screenTitle->industry)
    {
        changeScreen("industryElectricity", screenTitle, industryElectricity);
        prev->setText(tr("< Previous"));
    }
    else if (currentScreen == "industryElectricity")
    {
        changeScreen("industryHeat", industryElectricity, industryHeat);
    }
    else if (currentScreen == "industryHeat")
    {
        changeScreen("industrySteam", industryHeat, industrySteam);
    }
    else if (currentScreen == "industrySteam")
    {
        changeScreen("final", industrySteam, finalScreen);
        next->setText(tr("Send data"));
    }

    //FINAL SCREEN
    else if (currentScreen == "final")
    {
        if (!dataSent)
        {
            createDataString();
            finalScreen->sendData();
            next->setText(tr("Quit"));
            dataSent = true;
        }
        else
            qApp->quit();
    }
}

void MainWindow::createDataString()
{
    QString str = "";

    //Screen Title
    if (screenTitle->home)      str += "profile=Home";
    if (screenTitle->industry)  str += "profile=Industry";
    str += "&";

    //Screen Home Consumption
    str += "sh1-en_cons=";      str += toStr(homeElectricity->energy_consumption);  str += "&";
    str += "sh1-en_price=";     str += toStr(homeElectricity->energy_price);        str += "&";
    str += "sh1-en_bprice=";    str += toStr(homeElectricity->energy_basePrice);    str += "&";
    str += "sh1-he_cons=";      str += toStr(homeHeat->heat_consumption);           str += "&";
    str += "sh1-he_price=";     str += toStr(homeHeat->heat_price);                 str += "&";
    str += "sh1-gas=";          str += (homeHeat->gas) ? "true" : "false";          str += "&";
    str += "sh1-oil=";          str += (homeHeat->oil) ? "true" : "false";          str += "&";
    str += "sh1-hotwater=";     str += (homeHeat->hotWater) ? "true" : "false";     str += "&";

    //Screen Home PV
    str += "sh2-surf=";     str += toStr(homePV->surface);  str += "&";
    str += "sh2-dir=";      str += homePV->direction;       str += "&";
    str += "sh2-angle=";    str += toStr(homePV->angle);    str += "&";

    //Screen Home Habitat
    str += "sh3-mehr=";     str += (homeHabitat->mehrFamHaus) ? "true" : "false";   str += "&";
    str += "sh3-ein=";      str += (homeHabitat->einFamHaus) ? "true" : "false";    str += "&";
    str += "sh3-wohn=";     str += (homeHabitat->wohnung) ? "true" : "false";       str += "&";
    str += "sh3-eigen=";    str += (homeHabitat->eigentuemer) ? "true" : "false";   str += "&";
    str += "sh3-miete=";    str += (homeHabitat->miete) ? "true" : "false";         str += "&";

    //Screen Industry Consumption
    str += "si1-cons=";     str += toStr(industryElectricity->consumption);         str += "&";
    str += "si1-htap=";     str += toStr(industryElectricity->hTArbPreis);          str += "&";
    str += "si1-ntap=";     str += toStr(industryElectricity->nTArbPreis);          str += "&";
    str += "si1-netz=";     str += toStr(industryElectricity->netzkosten);          str += "&";
    str += "si1-eeg=";      str += (industryElectricity->eEG) ? "true" : "false";   str += "&";
    str += "si1-kwk=";      str += toStr(industryElectricity->kWK);                 str += "&";
    str += "si1-strsmg=";   str += toStr(industryElectricity->stromstG);            str += "&";
    str += "si1-off=";      str += toStr(industryElectricity->offshore);            str += "&";
    str += "si1-leist=";    str += toStr(industryElectricity->leistung);            str += "&";

    //Screen Industry Steam

    //Final Screen
    str += "name=";         str += finalScreen->name;       str += "&";
    str += "address=";      str += finalScreen->address;    str += "&";
    str += "phone=";        str += finalScreen->phone;      str += "&";
    str += "email=";        str += finalScreen->email;

    //Sending data string
    finalScreen->setDataString(str);
}
