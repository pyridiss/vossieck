#ifndef SCREENTITLE_H
#define SCREENTITLE_H

#include <QWidget>

class ScreenTitle : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenTitle(QWidget *parent = 0);
    bool home;
    bool industry;

signals:
    
public slots:
    void setIndustry();
    void setHome();
};

#endif // SCREENTITLE_H
