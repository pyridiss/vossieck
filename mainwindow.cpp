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
    screenIndustry1 = new ScreenIndustry1(this);
    screenIndustry2 = new ScreenIndustry2(this);
    screenHome1 = new ScreenHome1(this);
    screenHome2 = new ScreenHome2(this);
    screenHome3 = new ScreenHome3(this);
    finalScreen = new FinalScreen(this);

    //Previous & Next
    prev = new QPushButton("Quit");
    next = new QPushButton("Next >");

    //Grid Layout
    layoutMainWindow.addWidget(title, 0, 0, 1, 2);
    layoutMainWindow.addWidget(screenTitle, 1, 0, 1, 2);
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
    else if (currentScreen == "industry1")
    {
        changeScreen("title", screenIndustry1, screenTitle);
        prev->setText("Quit");
    }
    else if (currentScreen == "home1")
    {
        changeScreen("title", screenHome1, screenTitle);
        prev->setText("Quit");
    }
    else if (currentScreen == "industry2")
        changeScreen("industry1", screenIndustry2, screenIndustry1);

    else if (currentScreen == "home2")
        changeScreen("home1", screenHome2, screenHome1);

    else if (currentScreen == "home3")
        changeScreen("home2", screenHome3, screenHome2);

    else if (currentScreen == "final")
    {
        if (screenTitle->industryChecked)   changeScreen("industry2", finalScreen, screenIndustry2);
        if (screenTitle->homeChecked)       changeScreen("home3", finalScreen, screenHome3);
        next->setText("Next >");
    }
}

void MainWindow::nextScreen()
{
    if (currentScreen == "title" && screenTitle->homeChecked)
    {
        changeScreen("home1", screenTitle, screenHome1);
        prev->setText("< Previous");
    }
    else if (currentScreen == "title" && screenTitle->industryChecked)
    {
        changeScreen("industry1", screenTitle, screenIndustry1);
        prev->setText("< Previous");
    }
    else if (currentScreen == "industry1")
        changeScreen("industry2", screenIndustry1, screenIndustry2);

    else if (currentScreen == "home1")
        changeScreen("home2", screenHome1, screenHome2);

    else if (currentScreen == "home2")
        changeScreen("home3", screenHome2, screenHome3);

    else if (currentScreen == "industry2" || currentScreen == "home3")
    {
        if (currentScreen == "industry2")   changeScreen("final", screenIndustry2, finalScreen);
        if (currentScreen == "home3")       changeScreen("final", screenHome3, finalScreen);
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
    finalScreen->setDataString("valeur=100");
}
