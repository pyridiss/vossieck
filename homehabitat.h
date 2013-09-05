#ifndef SCREENHOME3_H
#define SCREENHOME3_H

#include <QWidget>

class HomeHabitat : public QWidget
{
    Q_OBJECT
public:
    explicit HomeHabitat(QWidget *parent = 0);

public:
    bool mehrFamHausChecked;
    bool einFamHausChecked;
    bool wohnungChecked;

    bool eigentuemerChecked;
    bool mieteChecked;

signals:
    
public slots:
    void setMehrFamHausChecked();
    void setEinFamHausChecked();
    void setWohnungChecked();

    void setEigentuemerChecked();
    void setMieteChecked();
};

#endif // SCREENHOME3_H
