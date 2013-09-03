#ifndef SCREENHOME3_H
#define SCREENHOME3_H

#include <QWidget>

class ScreenHome3 : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenHome3(QWidget *parent = 0);

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
