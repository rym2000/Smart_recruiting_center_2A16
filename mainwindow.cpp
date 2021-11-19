#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evaluation.h"
#include <QMessageBox>
#include <delegate.h>
#include <QSqlQuery>

#include <SmtpMime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Evaluation e;
    ui->lineEdit->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_3->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_4->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_5->setValidator( new QIntValidator(0, 99999999, this) );

    ui->lineEdit->setMaxLength(8);
    ui->lineEdit_5->setMaxLength(8);

    ui->lineEdit_3->setMaxLength(2);
    ui->lineEdit_4->setMaxLength(2);
    ui->lineEdit_2->setMaxLength(2);




    QPixmap bkgnd(":/new/prefix1/res/back.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        QString el1 = "EL1";
        QString el2 = "EL2";
        QString el3 = "EL3";
        ui->comboBox_3->addItem("trier par code");
        ui->comboBox_3->addItem("trier par numerique");
        ui->comboBox_3->addItem("trier par linguistique");
        ui->comboBox_3->addItem("trier par motivation");

        ui->comboBox->addItem(el1);
        ui->comboBox->addItem(el2);
        ui->comboBox->addItem(el3);
        QSqlQuery q;
        q.prepare("select code from mycrud;");

         if(q.exec()){
             while(q.next()){
                     QString a=q.value(0).toString();
                    ui->comboBox_2->addItem(a);



             }
         }



}
int  changed = 0;
MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::referesh(){
    ui->tableView->setModel(e.afficher(this));
    ui->comboBox_2->setModel(e.afficherCode());


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
            ui->tableView->setModel(e.afficher(this));
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



         }
        else{
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("Erreur.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }
        referesh();


}

void MainWindow::on_pushButton_2_clicked()
{
   referesh();

}

void MainWindow::on_pushButton_6_clicked()
{



    bool test=e.supprimer(ui->comboBox_2->currentData().toInt());

    if(test)
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supression effectué .\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec suprresion.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
    referesh();

}

void MainWindow::on_pushButton_7_clicked()
{
    int code = ui->lineEdit_5->text().toInt();
    // int noteCl= ui->lineEdit_2->text().toInt();
     // int noteCn= ui->lineEdit_3->text().toInt();
    //  int noteM= ui->lineEdit_4->text().toInt();
     // QString type = ui->comboBox->currentText();


         bool teste=e.modifier(code);
       if(teste)
         {
           // ui->tableView->setModel((e.afficher()));
            QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                              QObject::tr("  modifié ! \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
         }

         else {

             QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    Delegate *d= new Delegate();
    QWidget * e=d->create(ui->tableView);
    d->set(e,index);

int line=index.row();
int col1=index.column();
 QModelIndex b=ui->tableView->model()->index(line,col1,QModelIndex());
 QVariant f=b.data(Qt::DisplayRole);
int code= ui->tableView->model()->index(line,0,QModelIndex()).data(Qt::DisplayRole).toInt();

 QString val_modif = f.toString();
 QSqlQuery query;
 if(col1==0){
     QMessageBox::critical(nullptr, QObject::tr("erreur"),
                 QObject::tr(" vous ne pouvez "
                             "pas modifier le code."), QMessageBox::Cancel);

 }
 if(col1==1){
     query.prepare("update mycrud set note_cl=:notecl where code=:code");
     query.bindValue(":notecl",val_modif.toInt());
     query.bindValue(":code",code);
    if(query.exec()){
        QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                          QObject::tr("  modifié ! \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }



 }
 if(col1==2){
     query.prepare("update mycrud set note_cn=:notecn where code=:code");
     query.bindValue(":notecn",val_modif.toInt());
     query.bindValue(":code",code);
    if(query.exec()){
        QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                          QObject::tr("  modifié ! \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }



 }
 if(col1==3){
     query.prepare("update mycrud set note_m=:notem where code=:code");
     query.bindValue(":notem",val_modif.toInt());
     query.bindValue(":code",code);
    if(query.exec()){
        QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                          QObject::tr("  modifié ! \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }



 }
 if(col1==4){
     query.prepare("update mycrud set type=:type where code=:code");
     query.bindValue(":type",val_modif.toInt());
     query.bindValue(":code",code);
    if(query.exec()){
        QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                          QObject::tr("  modifié ! \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }



 }
 referesh();




}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    Evaluation e;
   ui->tableView->setModel(e.recherche(arg1,this));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{   int note=arg1.toInt();

        if(ui->lineEdit_2->text().toInt()>20){
            ui->lineEdit_2->clear();
            QMessageBox::critical(nullptr, QObject::tr("erreur"),
                        QObject::tr(" merci de mettre une note  "
                                    "inferieur a 20."), QMessageBox::Cancel);

        }





}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    int note=arg1.toInt();

            if(ui->lineEdit_3->text().toInt()>20){
                ui->lineEdit_3->clear();
                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                            QObject::tr(" merci de mettre une note  "
                                        "inferieur a 20."), QMessageBox::Cancel);

            }



}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    int note=arg1.toInt();

            if(ui->lineEdit_4->text().toInt()>20){
                ui->lineEdit_4->clear();
                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                            QObject::tr(" merci de mettre une note  "
                                        "inferieur a 20."), QMessageBox::Cancel);

            }


}



void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    if(!changed){
        ui->lineEdit_6->clear();
    }
    else{
        changed=0;
    }

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    int code = arg1.toInt();
    QSqlQuery query;
    query.prepare("select (note_cl+note_cn+note_m)/3 from mycrud where code = ?");
    query.addBindValue(code);


    if(query.exec()){
        changed=1;
        while(query.next()){
            QString moy = query.value(0).toString();
            ui->lineEdit_6->setText(moy);


        }
    }




}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    Evaluation e;
    ui->label->setNum(index);
   ui->tableView->setModel(e.trier(this,index));
}

void MainWindow::on_pushButton_5_clicked()
{
    Evaluation e;
    QSqlQuery query;
       //QString val = ui->label_pdf->text();
       query.prepare("select * from mycrud ");
 e.telechargerPDF();
//       if(query.exec()){

//           while(query.next())
//           {


//          ui->lineEdit->setText(query.value(0).toString());
//          ui->lineEdit_2->setText(query.value(1).toString());
//           ui->lineEdit_3->setText(query.value(2).toString());
//           ui->lineEdit_4->setText(query.value(3).toString());
//           ui->comboBox->addItem(query.value(4).toString());



//      }
//       }

//           QMessageBox::critical(nullptr, QObject::tr(" echoué"),
//                       QObject::tr("Erreur !.\n"
//                                   "Click Cancel to exit."), QMessageBox::Cancel);

        QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

   }




void MainWindow::on_pushButton_4_clicked()
{
    // This is a first demo application of the SmtpClient for Qt project

    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)



}

//void MainWindow::on_pushButton_5_clicked()
//{
//    Evaluation e;
//    QSqlQuery query;
//       //QString val = ui->label_pdf->text();
//       query.prepare("select * from mycrud ");
// e.telechargerPDF();
//       if(query.exec()){
//           while(query.next())
//           {


//        ui->lineEdit->setText(query.value(0).toString());
//          ui->lineEdit_2->setText(query.value(1).toString());
//           ui->lineEdit_3->setText(query.value(2).toString());
//           ui->lineEdit_4->setText(query.value(3).toString());
//           ui->comboBox->addItem(query.value(4).toString());



//      }
//       }

//           QMessageBox::critical(nullptr, QObject::tr(" echoué"),
//                       QObject::tr("Erreur !.\n"
//                                   "Click Cancel to exit."), QMessageBox::Cancel);

//        QMessageBox::information(nullptr,QObject::tr("OK"),
//                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

//}
