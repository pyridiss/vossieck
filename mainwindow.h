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
#include "screenindustry1.h"
#include "screenindustry2.h"

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=0);
    QPixmap& loadLogo();

public:
    QGridLayout layoutMainWindow;

    QPushButton *prev;
    QPushButton *next;

    ScreenTitle* screenTitle;
    ScreenIndustry1* screenIndustry1;
    ScreenIndustry2* screenIndustry2;
    ScreenHome1* screenHome1;
    ScreenHome2* screenHome2;

    QGroupBox *groupTitle;
    QGroupBox *groupIndustry1;
    QGroupBox *groupIndustry2;
    QGroupBox *groupHome1;
    QGroupBox *groupHome2;

public:
    string currentScreen;

private slots:
    void previousScreen();
    void nextScreen();
};

#endif // MAINWINDOW_H
