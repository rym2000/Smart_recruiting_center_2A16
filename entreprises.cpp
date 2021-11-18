#include "entreprises.h"
#include "ui_entreprises.h"
#include "QMessageBox"
#include "QIntValidator"
#include "QSqlQuery"
#include "QStringListModel"
#include <QFile>
#include <QTextStream>
#include "smtp.h"
#include "Excel.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QVariant>






Entreprises::Entreprises(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entreprises)
{
    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator (0, 9999 , this));
    ui->le_delai->setValidator( new QIntValidator (0, 99, this));
    ui->tab_entreprises->setModel(E.afficher());
    ui->comboBox->setModel(E.afficher());
}

Entreprises::~Entreprises()
{
    delete ui;
}
void Entreprises::on_pushButton_ajouter_clicked()
{
    int identifiant=ui->id->text().toInt();
    QString nom=ui->le_nom->text();
    QString offre=ui->le_offre->text();
    int delai=ui->le_delai->text().toInt();
    QString adresse_mail=ui->mail->text();
    Entreprise E(identifiant , nom , offre , delai , adresse_mail );
    bool test=E.ajouter();
    QMessageBox msgBox;
    if (test)
       { ui->tab_entreprises->setModel(E.afficher());
     msgBox.setText("ajout avec succes");
        msgBox.exec();}
    else
     msgBox.setText("ajout failed");
    msgBox.exec();


}

void Entreprises::on_pushButton_supprimer_clicked()
{
    int identifiant=ui->comboBox->currentText().toInt();
    bool test = E.supprimer(identifiant);
    QMessageBox msgBox;
    if (test)
       { ui->tab_entreprises->setModel(E.afficher());
     msgBox.setText("suppression avec succes");
        msgBox.exec();}
    else
     msgBox.setText("suppression failed");
    msgBox.exec();

}

void Entreprises::on_pushButton_modifier_clicked()
{
    int identifiant = ui->id->text().toInt();
        QString nom= ui->le_nom->text();
        QString offre= ui->le_offre->text();
        int delai = ui->le_delai->text().toInt();
        QString adresse_mail= ui->mail->text();

      Entreprise E (identifiant,nom,offre , delai , adresse_mail);


      bool test=E.modifier(identifiant,nom,offre,delai , adresse_mail);
      if(test)
    { //refresh
    QMessageBox::information(nullptr, QObject::tr(" modification successful"),
                      QObject::tr("Modification Done.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modification failed"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_entreprises->setModel(E.afficher());


    }


void Entreprises::on_pushButton_trier_clicked()
{

        Entreprise E;
        ui->tab_entreprises->setModel(E.trier());
    }






void Entreprises::on_comboBox_activated(const QString &arg1)
{
    int id = ui->comboBox->currentText().toInt();
         QString id_string= QString::number(id);
                QSqlQuery query;
                query.prepare("select * from ENTREPRISE where IDENTIFIANT='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->le_nom->setText(query.value(1).toString());
                   ui->id->setText(query.value(0).toString());

                    ui->le_offre->setText(query.value(2).toString());
                    ui->le_delai->setText(query.value(3).toString());
                    ui->mail->setText(query.value(4).toString());

    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void Entreprises::on_pushButton_trier1_clicked()
{
    Entreprise E;
    ui->tab_entreprises->setModel(E.trier1());
}

void Entreprises::on_pushButton_trier2_clicked()
{
    Entreprise E;
    ui->tab_entreprises->setModel(E.trier2());
}

void Entreprises::on_rech_textChanged(const QString &arg1)
{
    Entreprise E;

    int identifiant = ui->rech->text().toInt();
        QString nom = ui->rech->text();
         QString offre= ui->rech->text();

        E.rechercher(ui->tab_entreprises,identifiant,nom,offre);
        if (ui->rech->text().isEmpty())
        {
           ui->tab_entreprises->setModel(E.afficher());
        }
        }


void Entreprises::on_pushButton_browse_email_clicked()
{
    files.clear();

       QFileDialog dialog(this);
       dialog.setDirectory(QDir::homePath());
       dialog.setFileMode(QFileDialog::ExistingFiles);

       if (dialog.exec())
           files = dialog.selectedFiles();

       QString fileListString;
       foreach(QString file, files)
           fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

       ui->lineEdit_atchmnt_email->setText( fileListString );
}

void Entreprises::on_pushButton_send_email_clicked()
{
    //    QSslConfiguration sslCfg = QSslConfiguration::defaultConfiguration();
        //    QList<QSslCertificate> ca_list = sslCfg.caCertificates();
        //    QList<QSslCertificate> ca_new = QSslCertificate::fromData("CaCertificates");
        //    ca_list += ca_new;

        //    sslCfg.setCaCertificates(ca_list);

        //    sslCfg.setProtocol( QSsl::TlsV1SslV3 );

        //    QSslConfiguration::setDefaultConfiguration(sslCfg);

            qDebug() <<  "Loaded SSL Library version: " << QSslSocket::sslLibraryVersionString();

            // ui->lineEdit_to_email->setText("email_ili_bch_tab3athlou@gmail.com");
            // ui->lineEdit_from_email->setText("email_ili_bch_tab3ith_minou@gmail.com");
            // ui->lineEdit_psswrd_email->setText("mdp mta3 l email ili bch tab3th minou");

            // ui->lineEdit_subject_email->setText("test subject");
            // ui->textEdit_email->setText("test text");

            QString from = ui->lineEdit_from_email->text();
            QString to = ui->lineEdit_to_email->text();
            QString subject = ui->lineEdit_subject_email->text();
            QString password = ui->lineEdit_psswrd_email->text();
            QString email_text = ui->textEdit_email->toPlainText();

            Smtp* smtp = new Smtp(from, password);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            if( !files.isEmpty() )
                smtp->sendMail(from, to, subject, email_text, files);
            else
                smtp->sendMail(from, to, subject, email_text);
}
void   Entreprises::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email->clear();
    ui->lineEdit_subject_email->clear();
    ui->lineEdit_atchmnt_email->clear();
    ui->textEdit_email->clear();
    ui->lineEdit_psswrd_email->clear();
}

void Entreprises::on_exporterExel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            EXCEL obj(fileName, "mydata", ui->tab_entreprises);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "identifiant", "char(20)");
            obj.addField(1, "nom", "char(20)");
            obj.addField(2, "offre", "char(20)");
            obj.addField(3, "delai", "char(20)");
            obj.addField(4, "adresse_mail", "char(20)");



            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}
