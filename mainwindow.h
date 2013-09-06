#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>

#include <string>

#include "screentitle.h"
#include "homeconsumption.h"
#include "homepv.h"
#include "homehabitat.h"
#include "industryconsumption.h"
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
    IndustryConsumption*    industryConsumption;
    ScreenIndustry2*        screenIndustry2;
    HomeConsumption*        homeConsumption;
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
