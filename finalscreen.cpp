#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include "finalscreen.h"

FinalScreen::FinalScreen(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label = new QLabel("<span style='font-size: 20pt;'>Final Screen</span>");
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    labelError = new QLabel;

    QPushButton *button = new QPushButton("Click here to send data");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(label, 0, 0, 1, 1);
    layout->addWidget(button, 1, 0, 1, 1);
    layout->addWidget(labelError, 2, 0, 1, 1);

    setLayout(layout);

    connect(button, SIGNAL(clicked()), this, SLOT(sendData()));
}

void FinalScreen::setDataString(QString _new)
{
    data = _new;
}

void FinalScreen::sendData()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QUrl url("http://quentin.henriet.free.fr/Avossieck.php?" + data);
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    if (reply->error() != QNetworkReply::NoError)
        labelError->setText(reply->errorString());
}
