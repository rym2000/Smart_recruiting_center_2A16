#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QSound>
#include "smtp.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableContrat->setModel(co.afficher());
    QSound::play("C:/Users/mEtrOpOliS/Downloads/ludwig-van-beethovens-5th-symphony-in-c-minor-full.wav");
    QPixmap pix("C:/Users/mEtrOpOliS/Desktop/bg bleu.png");
    ui->label_9->setPixmap(pix);
    QIntValidator *val=new QIntValidator(100000,999999,this);
    ui->id->setValidator(val);
    ui->idSupp->setValidator(val);
    QRegExp rx("[A-Za-z]{0,255}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->nom->setValidator(validator);
    ui->prenom->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    float duree=ui->duree->text().toFloat();
    QString type=ui->type->currentText();
    contrat c(id,nom,prenom,duree,type);
    bool test=c.ajouter();
    if(test==true)
    {
        ui->tableContrat->setModel(co.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat ajouté","success",QSystemTrayIcon::Information,10000);
    }
else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat non ajouté","erreur",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->idSupp->text().toInt();
    bool test=co.supprimer(id);
    if(test==true)
    {
        ui->tableContrat->setModel(co.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat supprimé","success",QSystemTrayIcon::Information,10000);
    }
else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat non supprimé","erreur",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    float duree=ui->duree->text().toFloat();
    QString type=ui->type->currentText();
    contrat c(id,nom,prenom,duree,type);
    bool test=c.modifier(id);
    if(test==true)
    {
        ui->tableContrat->setModel(co.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat modifié","success",QSystemTrayIcon::Information,10000);
    }
else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                            notifier->setIcon(QIcon(""));
                             notifier->show();
                             notifier->showMessage(" contrat non modifié","erreur",QSystemTrayIcon::Critical,10000);
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    QString critere=ui->critereTri->currentText();
     ui->tableContrat->setModel(co.trier(critere));
}

void MainWindow::on_pushButton_5_clicked()
{
    Smtp* smtp = new Smtp("hiba.jalel@esprit.tn", "201JMT3332", "smtp.gmail.com", 465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
       smtp->sendMail("hiba.jalel@esprit.tn",ui->lineEditMail->text(),ui->lineEditObjet->text(),ui->Message->toPlainText());
}
