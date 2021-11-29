#include "authentification.h"
#include "ui_authentification.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

       animation = new QPropertyAnimation(ui->identifier,"geometry");
       animationimg = new QPropertyAnimation(ui->widget,"geometry");
       animation->setDuration(1000);
       animationimg->setDuration(1000);
       animation->setStartValue(ui->identifier->geometry());
       animationimg->setStartValue(ui->widget->geometry());
       animation->setEndValue(QRect(300,310,131,31));
       animationimg->setEndValue(QRect(20,110,711,351));
       curve.setType(QEasingCurve::OutBounce);
       curve.setType(QEasingCurve::OutBounce);
       animation->setEasingCurve(curve);
       animationimg->setEasingCurve(curve1);
       animation->setLoopCount(3);
       animationimg->setLoopCount(1);
       animation->start();
       animationimg->start();
}

login::~login()
{
    delete ui;
}
