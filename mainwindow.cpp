#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QGridLayout>

#include <string>
#include <iostream>

#include "mainwindow.h"
#include "screentitle.h"
#include "screenindustry1.h"
#include "screenhome1.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    currentScreen = "title";

    //Application Title
    QLabel *title = new QLabel;
    title->setAlignment(Qt::AlignHCenter);
    title->setText("<span style='font-size:24pt;'>Doc4Energy</span>");

    //Groupboxes
    groupTitle = new QGroupBox(tr("Choose your profile:"));
    groupIndustry1 = new QGroupBox(tr("Industry: Page 1/?"));
    groupIndustry2 = new QGroupBox(tr("Industry: Page 2/?"));
    groupHome1 = new QGroupBox(tr("Home: Page 1/?"));
    groupHome2 = new QGroupBox(tr("Home: Page 2/?"));

    //Screens
    screenTitle = new ScreenTitle(groupTitle);
    screenIndustry1 = new ScreenIndustry1(groupIndustry1);
    screenIndustry2 = new ScreenIndustry2(groupIndustry2);
    screenHome1 = new ScreenHome1(groupHome1);
    screenHome2 = new ScreenHome2(groupHome2);

    //Layouts for screens
    QGridLayout *layoutScreenTitle = new QGridLayout;
    layoutScreenTitle->addWidget(screenTitle, 0, 0, 1, 1);
    groupTitle->setLayout(layoutScreenTitle);

    QGridLayout *layoutScreenIndustry1 = new QGridLayout;
    layoutScreenIndustry1->addWidget(screenIndustry1, 0, 0, 1, 1);
    groupIndustry1->setLayout(layoutScreenIndustry1);

    QGridLayout *layoutScreenIndustry2 = new QGridLayout;
    layoutScreenIndustry2->addWidget(screenIndustry2, 0, 0, 1, 1);
    groupIndustry2->setLayout(layoutScreenIndustry2);

    QGridLayout *layoutScreenHome1 = new QGridLayout;
    layoutScreenHome1->addWidget(screenHome1, 0, 0, 1, 1);
    groupHome1->setLayout(layoutScreenHome1);

    QGridLayout *layoutScreenHome2 = new QGridLayout;
    layoutScreenHome2->addWidget(screenHome2, 0, 0, 1, 1);
    groupHome2->setLayout(layoutScreenHome2);

    //Previous & Next
    prev = new QPushButton("Quit");
    next = new QPushButton("Next >");

    //Grid Layout
    layoutMainWindow.addWidget(title, 0, 0, 1, 2);
    layoutMainWindow.addWidget(groupTitle, 1, 0, 1, 2);
    layoutMainWindow.addWidget(prev, 2, 0, 1, 1);
    layoutMainWindow.addWidget(next, 2, 1, 1, 1);
    layoutMainWindow.setRowStretch(0, 0);
    layoutMainWindow.setRowStretch(1, 1);
    layoutMainWindow.setRowStretch(2, 0);
    setLayout(&layoutMainWindow);

    connect(prev, SIGNAL(clicked()), this, SLOT(previousScreen()));
    connect(next, SIGNAL(clicked()), this, SLOT(nextScreen()));
}

void MainWindow::previousScreen()
{
    if (currentScreen == "title")
    {
        qApp->quit();
    }
    else if (currentScreen == "industry1")
    {
        layoutMainWindow.removeWidget(groupIndustry1);
        layoutMainWindow.addWidget(groupTitle, 1, 0, 1, 2);
        groupIndustry1->hide();
        groupTitle->show();
        currentScreen = "title";
        prev->setText("Quit");
    }
    else if (currentScreen == "industry2")
    {
        layoutMainWindow.removeWidget(groupIndustry2);
        layoutMainWindow.addWidget(groupIndustry1, 1, 0, 1, 2);
        groupIndustry2->hide();
        groupIndustry1->show();
        currentScreen = "industry1";
        next->setText("Next >");
    }
    else if (currentScreen == "home1")
    {
        layoutMainWindow.removeWidget(groupHome1);
        layoutMainWindow.addWidget(groupTitle, 1, 0, 1, 2);
        groupHome1->hide();
        groupTitle->show();
        currentScreen = "title";
        prev->setText("Quit");
    }
    else if (currentScreen == "home2")
    {
        layoutMainWindow.removeWidget(groupHome2);
        layoutMainWindow.addWidget(groupHome1, 1, 0, 1, 2);
        groupHome2->hide();
        groupHome1->show();
        currentScreen = "home1";
        next->setText("Next >");
    }
}

void MainWindow::nextScreen()
{
    if (currentScreen == "title" && screenTitle->homeChecked)
    {
        layoutMainWindow.removeWidget(groupTitle);
        groupTitle->hide();
        groupHome1->show();
        layoutMainWindow.addWidget(groupHome1, 1, 0, 1, 2);
        currentScreen = "home1";
        prev->setText("< Previous");
    }
    else if (currentScreen == "title" && screenTitle->industryChecked)
    {
        layoutMainWindow.removeWidget(groupTitle);
        groupTitle->hide();
        groupIndustry1->show();
        layoutMainWindow.addWidget(groupIndustry1, 1, 0, 1, 2);
        currentScreen = "industry1";
        prev->setText("< Previous");
    }
    else if (currentScreen == "industry1")
    {
        layoutMainWindow.removeWidget(groupIndustry1);
        groupIndustry1->hide();
        groupIndustry2->show();
        layoutMainWindow.addWidget(groupIndustry2, 1, 0, 1, 2);
        currentScreen = "industry2";
        next->setText("Quit");
    }
    else if (currentScreen == "home1")
    {
        layoutMainWindow.removeWidget(groupHome1);
        groupHome1->hide();
        groupHome2->show();
        layoutMainWindow.addWidget(groupHome2, 1, 0, 1, 2);
        currentScreen = "home2";
        next->setText("Quit");
    }
    else if (currentScreen == "industry2" || currentScreen == "home2")
    {
        qApp->quit();
    }
}
