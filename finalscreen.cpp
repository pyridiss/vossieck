#include <QLabel>
#include <QLineEdit>
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
    QLabel *label = new QLabel("<span style='font-size: 20pt;'>Personal informations</span>");
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *labelName   = new QLabel("Name");
    QLabel *labelAdress = new QLabel("Adress");
    QLabel *labelPhone  = new QLabel("Phone number");
    QLabel *labelEmail  = new QLabel("Email adress");

    QLineEdit *lineName = new QLineEdit();
    QLineEdit *lineAdress = new QLineEdit();
    QLineEdit *linePhone = new QLineEdit();
    QLineEdit *lineEmail = new QLineEdit();

    QPushButton *button = new QPushButton("Click here to send data");
    labelError = new QLabel;

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(label, 0, 0, 1, 2);
    layout->addWidget(labelName, 1, 0, 1, 1);
    layout->addWidget(labelAdress, 2, 0, 1, 1);
    layout->addWidget(labelPhone, 3, 0, 1, 1);
    layout->addWidget(labelEmail, 4, 0, 1, 1);
    layout->addWidget(lineName, 1, 1, 1, 1);
    layout->addWidget(lineAdress, 2, 1, 1, 1);
    layout->addWidget(linePhone, 3, 1, 1, 1);
    layout->addWidget(lineEmail, 4, 1, 1, 1);
    layout->addWidget(button, 5, 0, 1, 2);
    layout->addWidget(labelError, 6, 0, 1, 2);

    setLayout(layout);

    connect(lineName,   SIGNAL(textEdited(QString)),    this, SLOT(setName(QString)));
    connect(lineAdress, SIGNAL(textEdited(QString)),    this, SLOT(setAdress(QString)));
    connect(linePhone,  SIGNAL(textEdited(QString)),    this, SLOT(setPhone(QString)));
    connect(lineEmail,  SIGNAL(textEdited(QString)),    this, SLOT(setEmail(QString)));
    connect(button,     SIGNAL(clicked()),              this, SLOT(sendData()));

    //Signals to stop editing fields
    connect(lineName,   SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineAdress, SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(linePhone,  SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineEmail,  SIGNAL(returnPressed()),      this, SLOT(setFocus()));
}

void FinalScreen::setDataString(QString _new)
{
    data = _new;
}

void FinalScreen::sendData()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QUrl url("http://www.vossieck.com/app.php?" + data);
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    if (reply->error() != QNetworkReply::NoError)
        labelError->setText(reply->errorString());
}

void FinalScreen::setName(QString _new)
{
    name = _new;
}

void FinalScreen::setAdress(QString _new)
{
    adress = _new;
}

void FinalScreen::setPhone(QString _new)
{
    phone = _new;
}

void FinalScreen::setEmail(QString _new)
{
    email = _new;
}
