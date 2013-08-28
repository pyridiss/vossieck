#ifndef SCREENTITLE_H
#define SCREENTITLE_H

#include <QWidget>

class ScreenTitle : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenTitle(QWidget *parent = 0);
    bool homeChecked;
    bool industryChecked;

signals:
    
public slots:
    void checkIndustry();
    void checkHome();
};

#endif // SCREENTITLE_H
