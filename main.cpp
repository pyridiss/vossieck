#include <QApplication>
#include <QFont>
#include <QDesktopWidget>
#include <QIcon>

#include <sstream>

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

QString toStr(int i)
{
    stringstream out;
    out << i;
    QString str(out.str().c_str());
    return str;
}

QString toStr(double d)
{
    stringstream out;
    out.precision(8);
    out << d;
    QString str(out.str().c_str());
    return str;
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

    QIcon icon(":/Icon.png");
    window.setWindowIcon(icon);

    desktop = app.desktop();

    window.show();
    return app.exec();
}
