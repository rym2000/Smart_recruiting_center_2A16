#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableContrat->setModel(co.afficher());
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
    int id_entreprise=ui->id_entreprise->text().toInt();
    int id_candidat=ui->id_candidat->text().toInt();
    contrat c(id,nom,prenom,duree,type,id_candidat,id_entreprise);
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
    int id_entreprise=ui->id_entreprise->text().toInt();
    int id_candidat=ui->id_candidat->text().toInt();
    contrat c(id,nom,prenom,duree,type,id_candidat,id_entreprise);
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
