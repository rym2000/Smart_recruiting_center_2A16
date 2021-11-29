#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   QEasingCurve curve,curve1;
    ui->setupUi(this);


    animation = new QPropertyAnimation(ui->login,"geometry");
    animationimg = new QPropertyAnimation(ui->widget,"geometry");
    animation->setDuration(1000);
    animationimg->setDuration(1000);
    animation->setStartValue(ui->login->geometry());
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

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_login_clicked()
{
    QString nomuitlisateur=ui->nomnutilisateur->text();
        QString motdepasse=ui->motdepasse->text();

        if((nomuitlisateur=="firas" and motdepasse=="firas123")||(nomuitlisateur=="rym" and motdepasse=="rym123")||(nomuitlisateur=="hassen" and motdepasse=="hassen123")||(nomuitlisateur=="khaled" and motdepasse=="khaled123")||(nomuitlisateur=="ahmed" and motdepasse=="ahmed123")||(nomuitlisateur=="hiba" and motdepasse=="hiba123"))
        {


            QMessageBox::information(this,"identifier","nom d'utilisateur et mot de passe sont correct");
            //hide();
            Menu = new menu(this);
            Menu->show();
        }
        else if (nomuitlisateur==""&&motdepasse=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("s'il vous plait remplir les champs.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("nom d'utilisateur ou mot de passe ne sont pas correct.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        }
}
