#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QPixmap>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

#include "mainwindow.h"
#include "screentitle.h"
#include "screenindustry1.h"
#include "screenhome1.h"

//Defined in main.cpp
int getScreenWidth();
int getScreenHeight();

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    currentScreen = "title";
    sendData();
    //Application Logo
    QLabel *title = new QLabel;
    title->setAlignment(Qt::AlignHCenter);
    title->setPixmap(loadLogo());
    title->setScaledContents(true);

    //Groupboxes
    groupTitle = new QGroupBox("Choose your profile:");
    groupIndustry1 = new QGroupBox("Industry: Page 1/?");
    groupIndustry2 = new QGroupBox("Industry: Page 2/?");
    groupHome1 = new QGroupBox("Home: Page 1/?");
    groupHome2 = new QGroupBox("Home: Page 2/?");
    groupHome3 = new QGroupBox("Home: Page 3/?");

    //Screens
    screenTitle = new ScreenTitle(groupTitle);
    screenIndustry1 = new ScreenIndustry1(groupIndustry1);
    screenIndustry2 = new ScreenIndustry2(groupIndustry2);
    screenHome1 = new ScreenHome1(groupHome1);
    screenHome2 = new ScreenHome2(groupHome2);
    screenHome3 = new ScreenHome3(groupHome3);

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

    QGridLayout *layoutScreenHome3 = new QGridLayout;
    layoutScreenHome3->addWidget(screenHome3, 0, 0, 1, 1);
    groupHome3->setLayout(layoutScreenHome3);

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
    }
    else if (currentScreen == "home3")
    {
        layoutMainWindow.removeWidget(groupHome3);
        layoutMainWindow.addWidget(groupHome2, 1, 0, 1, 2);
        groupHome3->hide();
        groupHome2->show();
        currentScreen = "home2";
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
    }
    else if (currentScreen == "home2")
    {
        layoutMainWindow.removeWidget(groupHome2);
        groupHome2->hide();
        groupHome3->show();
        layoutMainWindow.addWidget(groupHome3, 1, 0, 1, 2);
        currentScreen = "home3";
        next->setText("Quit");
    }
    else if (currentScreen == "industry2" || currentScreen == "home3")
    {
        qApp->quit();
    }
}

void MainWindow::sendData()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QUrl url("http://quentin.henriet.free.fr/vossieck.php?valeur=10");
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);
}
