#include "entretienn.h"
#include "ui_entretienn.h"
#include "QSqlQuery"

entretienn::entretienn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entretienn)
{
    ui->setupUi(this);
    Entretien e;


    QPixmap bkgnd(":/new/prefix1/res/back.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);


        ui->tableView_2->setModel(e.afficher());
ui->combo->setModel(e.afficher());
}

entretienn::~entretienn()
{
    delete ui;
}


void entretienn::on_pushButton_clicked()
{
    int Num = ui->Linenum->text().toInt();
    int Numposte = ui->linenumposte->text().toInt();
    QString Lieu = ui->linelieu->text();
    QString DateE = ui->linedate->text();
        Entretien e  = Entretien (Num,Lieu,Numposte,DateE);
        if(e.ajouter()){
            Entretien e;
            ui->tableView_2->setModel(e.afficher());
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

void entretienn::on_pushButton_2_clicked()
{
    Entretien e;
   ui->tableView_2->setModel(e.afficher());
   ui->combo->setModel(e.afficher());

}

void entretienn::on_pushButton_6_clicked()
{

    int Num =ui->combo->currentText().toInt();
    bool test=e.supprimer(Num);

    if(test)
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supression effectué .\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec suprresion.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
    ui->tableView_2->setModel(e.afficher());
}

void entretienn::on_pushButton_7_clicked()
{
    int Num = ui->Linenum->text().toInt();
    int Numposte = ui->linenumposte->text().toInt();
    QString Lieu = ui->linelieu->text();
    QString DateE = ui->linedate->text();
        Entretien e  = Entretien (Num,Lieu,Numposte,DateE);
         bool teste=e.modifier(Num,Numposte,Lieu,DateE);
       if(teste)
         {
            ui->tableView_2->setModel((e.afficher()));
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

void entretienn::on_pushButton_5_clicked()
{
    qDebug() <<  "Loaded SSL Library version: " << QSslSocket::sslLibraryVersionString();

          QString from = "khaledaziz.baccouche@esprit.tn";
          QString to = ui->lineEdit_14->text();
          QString subject = ui->lineEdit_13->text();
          QString password = "201JMT4097";
            QString email_text = ui->textEdit->toPlainText();

            Smtp* smtp = new Smtp(from, password);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMail(from, to, subject, email_text);
}


void entretienn::on_comboBox_activated(const QString &arg1)
{
    int Num = ui->combo->currentText().toInt();
       QString id_string= QString::number(Num);
              QSqlQuery query;
              query.prepare("select * from TABLE1 where NUM='"+id_string+"'");

              if(query.exec()){

                  while(query.next())
                  {
                      ui->linedate->setText(query.value(1).toString());
                 ui->Linenum->setText(query.value(0).toString());

                  ui->linelieu->setText(query.value(2).toString());
                  ui->linenumposte->setText(query.value(3).toString());

  }}
              else
                  QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}




void entretienn::on_pushButton_4_clicked()
{


      ui->tableView_2->setModel(e.triNumposte());

}


void entretienn::on_pushButton_3_clicked()
{
    Entretien e;

           int Num = ui->lineEdit_12->text().toInt();
            int Numposte = ui->lineEdit_12->text().toInt();


               e.rechercher(ui->tableView_2,Num,Numposte);
               if (ui->lineEdit_12->text().isEmpty())
               {
                  ui->tableView_2->setModel(e.afficher());
               }
}

