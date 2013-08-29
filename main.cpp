#include <QApplication>
#include <QFont>
#include <QDesktopWidget>

#include "mainwindow.h"

using namespace std;

QDesktopWidget* desktop;

int getScreenWidth()
{
    return desktop->availableGeometry().width();
}

int getScreenHeight()
{
    return desktop->availableGeometry().height();
}

/* Main function */
/* ************* */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QLocale::setDefault(QLocale::German);

    QFont font("Times", 12);
    QApplication::setFont(font);

    desktop = app.desktop();

    window.show();
    return app.exec();
}
