#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "industrysteam.h"

IndustrySteam::IndustrySteam(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label = new QLabel("<span style='font-size: 20pt;'>Screen Industry 2</span>");
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(label, 0, 0, 1, 1);
    setLayout(layout);
}
