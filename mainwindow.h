#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>

#include <string>

#include "screentitle.h"
#include "homeelectricity.h"
#include "homeheat.h"
#include "homepv.h"
#include "homehabitat.h"
#include "industryelectricity.h"
#include "industryheat.h"
#include "screenindustry2.h"
#include "finalscreen.h"

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=0);
    QPixmap& loadLogo();

private:
    bool dataSent;
private:
    void createDataString();
    void changeScreen(string _newTitle, QWidget* _oldScreen, QWidget* _newScreen);

public:
    QGridLayout layoutMainWindow;

    QPushButton *prev;
    QPushButton *next;

    ScreenTitle*            screenTitle;
    IndustryElectricity*    industryElectricity;
    IndustryHeat*           industryHeat;
    ScreenIndustry2*        screenIndustry2;
    HomeElectricity*        homeElectricity;
    HomeHeat*               homeHeat;
    HomePV*                 homePV;
    HomeHabitat*            homeHabitat;
    FinalScreen*            finalScreen;

public:
    string currentScreen;

private slots:
    void previousScreen();
    void nextScreen();
};

#endif // MAINWINDOW_H
