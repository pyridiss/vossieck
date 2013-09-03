#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>

#include <string>

#include "screentitle.h"
#include "screenhome1.h"
#include "screenhome2.h"
#include "screenhome3.h"
#include "screenindustry1.h"
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
    void createDataString();
    void changeScreen(string _newTitle, QWidget* _oldScreen, QWidget* _newScreen);

public:
    QGridLayout layoutMainWindow;

    QPushButton *prev;
    QPushButton *next;

    ScreenTitle* screenTitle;
    ScreenIndustry1* screenIndustry1;
    ScreenIndustry2* screenIndustry2;
    ScreenHome1* screenHome1;
    ScreenHome2* screenHome2;
    ScreenHome3* screenHome3;
    FinalScreen* finalScreen;

public:
    string currentScreen;

private slots:
    void previousScreen();
    void nextScreen();
};

#endif // MAINWINDOW_H
