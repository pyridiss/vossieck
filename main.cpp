#include <QApplication>
#include <QFont>

#include "mainwindow.h"

using namespace std;


/* Main function */
/* ************* */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QLocale::setDefault(QLocale::German);

    QFont font("Times", 12);
    QApplication::setFont(font);

    window.show();
    return app.exec();
}
