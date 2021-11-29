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
