#ifndef LOGIN_H
#define LOGIN_H
#include "gestioninscription.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private:
    Ui::login *ui;
    gestioninscription *ginscrition;
    QPropertyAnimation *animation,*animationimg;
};

#endif // LOGIN_H
