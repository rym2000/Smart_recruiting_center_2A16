#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_gestioninscription_clicked()
{
    ginscrition = new gestioninscription(this);
    ginscrition->show();
}

void menu::on_gestioninscription_5_clicked()
{
    Entreprise =new entreprises(this);

    Entreprise->show();
}

void menu::on_gestioninscription_2_clicked()
{
 entr = new entretienn(this);
 entr->show();
}
