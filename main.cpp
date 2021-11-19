#include "mainwindow.h"
#include "coonection.h"
#include <QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen* s= new QSplashScreen;
    s->setPixmap(QPixmap(":/new/prefix1/res/back.png"));
    s->show();

    MainWindow w;


    Connection c;
    bool test=c.createconnect();
    if(test)
    { QTimer::singleShot(5000,s,SLOT(close()));
        QTimer::singleShot(5000,&w,SLOT(show()));
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         qDebug()<<"hi!!";



}
    else{
        QTimer::singleShot(5000,s,SLOT(close()));
        QTimer::singleShot(5000,&w,SLOT(show()));
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
    return a.exec();
}
