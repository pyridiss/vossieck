#include "finalscreen.h"

FinalScreen::FinalScreen(QWidget *parent) :
    QWidget(parent)
{
}

void FinalScreen::setDataString(QString _new)
{
    data = _new;
}

/*

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

void MainWindow::createDataString()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QUrl url("http://quentin.henriet.free.fr/vossieck.php?valeur=10");
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);
}

*/
