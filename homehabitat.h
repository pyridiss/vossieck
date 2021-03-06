#ifndef HOMEHABITAT_H
#define HOMEHABITAT_H

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

    int surface;

signals:
    
public slots:
    void setMehrFamHaus();
    void setEinFamHaus();
    void setWohnung();

    void setEigentuemer();
    void setMiete();

    void setSurface(QString _new);
};

#endif // HOMEHABITAT_H
