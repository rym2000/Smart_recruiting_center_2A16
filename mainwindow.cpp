
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_gestioninscription_clicked()
{
    ginscrition = new gestioninscription(this);
    ginscrition->show();
}
