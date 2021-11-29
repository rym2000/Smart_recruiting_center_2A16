#include "user_interface.h"
#include "ui_user_interface.h"
#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QDate>

user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());

}

user_interface::~user_interface()
{
    delete ui;
}

void user_interface::on_pushButton_3_clicked()
{
    QString id = ui->id_line->text();
    QString nom= ui->nom_line->text();
    QString prenom= ui->prenom_line->text();
    QString salaire= ui->salaire_line->text();
    QString adresse_mail= ui->mail_line->text();
    QString mdp= ui->mdp_line->text();
    employe c(id,nom,prenom,salaire,adresse_mail,mdp);
    c.ajouter();
   ui->tableView->setModel(c.afficher());
}

void user_interface::on_pushButton_clicked()
{
    QString x = ui->lineEdit_4->text();
    ui->tableView_2->setModel(e.rechercher(x));
}

void user_interface::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit->text();
    e.supprimer(id);
    ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
        QObject::tr("employe supprimé.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
}


void user_interface::on_pushButton_4_clicked()
{

         QString id_modif= ui->lineEdit_2->text();
         QString nom= ui->new_nom->text();
         QString prenom= ui->new_prenom->text();
         QString salaire= ui->new_salaire->text();
         QString adresse_mail= ui->new_mail->text();
         QString mdp= ui->new_mdp->text();
           employe p(id_modif,nom,prenom,salaire,adresse_mail,mdp);
                        bool test =  p.modifier(id_modif,nom,prenom,salaire,adresse_mail,mdp);
                        if(test){
                            ui->tableView->setModel(e.afficher());
                            QMessageBox::information(nullptr,QObject::tr("employe modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
}
}

void user_interface::on_pushButton_5_clicked()
{
    QString x=ui->comboBox->currentText();
    ui->tableView->setModel(e.trier(x));
}
