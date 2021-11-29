#include "dialog.h"
#include "ui_dialog.h"
#include "employe.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString id = ui->id_line->text();
    QString nom= ui->nom_line->text();
    QString prenom= ui->prenom_line->text();
    QString salaire= ui->salaire_line->text();
    QString adresse_mail= ui->mail_line->text();
    QString mdp= ui->mdp_line->text();
    employe e(id,nom,prenom,salaire,adresse_mail,mdp);
}

void Dialog::on_pushButton_2_clicked()
{
       this->hide();
}
