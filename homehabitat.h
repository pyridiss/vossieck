#ifndef SCREENHOME3_H
#define SCREENHOME3_H

#include <QWidget>

class HomeHabitat : public QWidget
{
    Q_OBJECT
public:
    explicit HomeHabitat(QWidget *parent = 0);

public:
    bool mehrFamHaus;
    bool einFamHaus;
    bool wohnung;

    bool eigentuemer;
    bool miete;

signals:
    
public slots:
    void setMehrFamHaus();
    void setEinFamHaus();
    void setWohnung();

    void setEigentuemer();
    void setMiete();
};

#endif // SCREENHOME3_H
