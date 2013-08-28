#include <QApplication>

#include "mainwindow.h"

using namespace std;


/* Main function */
/* ************* */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QLocale::setDefault(QLocale::German);

    window.show();
    return app.exec();
}
