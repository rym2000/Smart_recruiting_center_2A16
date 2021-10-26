#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evaluation.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Evaluation e;
    ui->tableView->setModel(e.afficher());

    QPixmap bkgnd(":/new/prefix1/res/back.png");//chargement de l'image
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);//scale to set image size scalable with the menu
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        QString el1 = "EL1";
        QString el2 = "EL2";
        QString el3 = "EL3";
        ui->comboBox->addItem(el1);
        ui->comboBox->addItem(el2);
        ui->comboBox->addItem(el3);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    int code = ui->lineEdit->text().toInt();
    int noteCl = ui->lineEdit_2->text().toInt();
    int noteCn = ui->lineEdit_3->text().toInt();
    int noteM = ui->lineEdit_4->text().toInt();
    QString type = ui->comboBox->currentText();
        Evaluation e  = Evaluation(code,type,noteCl,noteCn,noteM);
        if(e.ajouter()){
            Evaluation e;
            ui->tableView->setModel(e.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



         }
        else{
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("ajout mahouch successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }


}

void MainWindow::on_pushButton_2_clicked()
{
    Evaluation e;
    ui->tableView->setModel(e.afficher());

}
