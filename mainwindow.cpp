#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user_interface.h"
#include "chat.h"
#include "ui_chat.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString mdp = ui->lineEdit_2->text();
    if ((id=="admin") & (mdp=="admin"))
    {
    user_interface * a=new user_interface;
   this->hide();
    a->show();
    QMessageBox::information(nullptr,QObject::tr("Login"),QObject::tr("Login en tant que admin"),QMessageBox::Cancel);
    }
    else if ( e.connecter(id,mdp))
    {
        QDialog * a=new chat;
            a->show();
            QMessageBox::information(nullptr,QObject::tr("Login"),QObject::tr("Login en tant que employé"),QMessageBox::Cancel);}
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Login"),QObject::tr("Login impossible"),QMessageBox::Cancel);
    }
}
