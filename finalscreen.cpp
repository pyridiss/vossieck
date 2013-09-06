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
    QLabel *title = new QLabel("<span style='font-size: 20pt;'>Personal information</span>");
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *text = new QLabel("Please, give us personal information, we will<br />contact you soon!");
    text->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel *labelName   = new QLabel("Name");           labelName->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelAddress = new QLabel("Address");       labelAddress->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelPhone  = new QLabel("Phone number");   labelPhone->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *labelEmail  = new QLabel("Email adress");   labelEmail->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *lineName = new QLineEdit();
    QLineEdit *lineAddress = new QLineEdit();
    QLineEdit *linePhone = new QLineEdit();
    QLineEdit *lineEmail = new QLineEdit();

    QPushButton *button = new QPushButton("Click here to send data");
    labelError = new QLabel;
    labelError->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(title, 0, 0, 1, 3);
    layout->addWidget(text, 1, 0, 1, 3);
    layout->addWidget(labelName, 2, 0, 1, 1);
    layout->addWidget(labelAddress, 3, 0, 1, 1);
    layout->addWidget(labelPhone, 4, 0, 1, 1);
    layout->addWidget(labelEmail, 5, 0, 1, 1);
    layout->addWidget(lineName, 2, 1, 1, 1);
    layout->addWidget(lineAddress, 3, 1, 1, 1);
    layout->addWidget(linePhone, 4, 1, 1, 1);
    layout->addWidget(lineEmail, 5, 1, 1, 1);
    layout->addWidget(button, 6, 1, 1, 1);
    layout->addWidget(labelError, 7, 0, 1, 3);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 2);
    layout->setColumnStretch(2, 1);
    setLayout(layout);

    connect(lineName,       SIGNAL(textEdited(QString)),    this, SLOT(setName(QString)));
    connect(lineAddress,    SIGNAL(textEdited(QString)),    this, SLOT(setAddress(QString)));
    connect(linePhone,      SIGNAL(textEdited(QString)),    this, SLOT(setPhone(QString)));
    connect(lineEmail,      SIGNAL(textEdited(QString)),    this, SLOT(setEmail(QString)));
    connect(button,         SIGNAL(clicked()),              this, SLOT(sendData()));

    //Signals to stop editing fields
    connect(lineName,       SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineAddress,    SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(linePhone,      SIGNAL(returnPressed()),      this, SLOT(setFocus()));
    connect(lineEmail,      SIGNAL(returnPressed()),      this, SLOT(setFocus()));
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
    else labelError->setText("Information sent!");
}

void FinalScreen::setName(QString _new)
{
    name = _new;
}

void FinalScreen::setAddress(QString _new)
{
    address = _new;
}

void FinalScreen::setPhone(QString _new)
{
    phone = _new;
}

void FinalScreen::setEmail(QString _new)
{
    email = _new;
}
