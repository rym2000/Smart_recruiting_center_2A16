#include "gestioninscription.h"
#include "ui_gestioninscription.h"
#include "candidat.h"
#include <QMessageBox>
#include<QSqlQuery>
#include <QSqlError>
#include "widget.h"
#include "qcustomplot.h"
#include "tableprinter.h"
#include <QMediaPlayer>
#include <QTimer>
#include<QDateTime>
#include"QDate"
#include <QTime>

using namespace DuarteCorporation;

gestioninscription::gestioninscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestioninscription)
{
    ui->setupUi(this);
    Candidat c;
    ui->tableView->setModel(c.afficher());


        QString el1 = "EL1";
        QString el2 = "EL2";
        QString el3 = "EL3";
        ui->comboBox->addItem(el1);
        ui->comboBox->addItem(el2);
        ui->comboBox->addItem(el3);

        QString a = "2015";
       QString b = "2016";
        QString d = "2015";
        QString e = "2017";
        QString f = "2018";
        QString g = "2019";
        QString h = "2020";
        QString i = "2021";
        QString j = "2022";
        QString k = "2023";
        QString l = "2024";
        QString m = "2025";
        QString n = "2026";
        QString o = "2027";
        QString p = "2028";
        QString q = "2029";
        QString r = "2030";
        QString s = "2031";
        ui->lineEdit_4->addItem(a);
        ui->lineEdit_4->addItem(b);
        ui->lineEdit_4->addItem(d);
        ui->lineEdit_4->addItem(e);
        ui->lineEdit_4->addItem(f);
        ui->lineEdit_4->addItem(g);
        ui->lineEdit_4->addItem(h);
        ui->lineEdit_4->addItem(i);
        ui->lineEdit_4->addItem(j);
        ui->lineEdit_4->addItem(k);
        ui->lineEdit_4->addItem(l);
        ui->lineEdit_4->addItem(m);
        ui->lineEdit_4->addItem(n);
        ui->lineEdit_4->addItem(o);
        ui->lineEdit_4->addItem(p);
        ui->lineEdit_4->addItem(q);
        ui->lineEdit_4->addItem(r);
        ui->lineEdit_4->addItem(d);

        //Timer
            QTimer *timer_p=new QTimer(this);
            connect(timer_p, SIGNAL(timeout()), this,SLOT(showTime()));
            timer_p->start(1000);

        //DAate systeme
            QDateTime Date_p=QDateTime::currentDateTime();
            QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
            ui->date->setText(Date_txt);


        reproductor = new QMediaPlayer(this);

       connect(ui->pushButton_playsong, &QPushButton::clicked, reproductor, &QMediaPlayer::play);
       connect(ui->pushButton_pausesong, &QPushButton::clicked, reproductor, &QMediaPlayer::pause);
       connect(ui->pushButton_stopsong, &QPushButton::clicked, reproductor, &QMediaPlayer::stop);

       //arduino
       int ret =A.connect_arduino();//lancer la connection to arduino
       switch (ret) {

       case(0):qDebug()<<"arduino is available and connect to : "<<A.getarduino_port_name();
           break;
       case(1):qDebug()<<"arduino is available and not  connect to : "<<A.getarduino_port_name();
           break;
       case(-1):qDebug()<<"arduino is not available ";
           break;

       }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(updatelabel()));

}

gestioninscription::~gestioninscription()
{
    delete ui;
}


void gestioninscription::updatelabel()
{

    data=A.read_from_arduino();//recuperer les donnes from arduino

    ui->label_7->setText("Aucune détection");

     if (data=="2")


        ui->label_7->setText("la poucentage de gaz dans la salle est faible s'il vous palit déactiver le sonor pour fermer les fenetres.");

    else if(data=="3")

           ui->label_7->setText("Attention !!!! la poucentage de gaz dans la salle est elevé s'il vous palit activer le sonor pour ouvrir les fenetres.");
}
void gestioninscription::on_pushButton_10_clicked()
{
    int CIN = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString date = ui->lineEdit_4->currentText();
    QString diplome = ui->comboBox->currentText();
        Candidat c  = Candidat(CIN,nom,prenom,date,diplome);
        if(ui->lineEdit->text().size()==8){
        if((ui->lineEdit->text()!="")&&(ui->lineEdit_2->text()!="")&&(ui->lineEdit_3->text()!="")){
        if(c.ajouter()){
            Candidat c;
            ui->tableView->setModel(c.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



         }
        else{
            QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                        QObject::tr("ajout echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }
        }
        else

           {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un candidat"),
                        QObject::tr("Verifier les champs !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un candidat"),
                        QObject::tr("s'il vou plait verifier votre CIN  !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void gestioninscription::on_pushButton_19_clicked()
{
    int CIN =ui->lineEdit_5->text().toUInt();
        bool test=c.supprimer(CIN);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(c.afficher());
}

void gestioninscription::on_pushButton_18_clicked()
{
    int CIN = ui->lineEdit_5->text().toInt();
    QString nom = ui->lineEdit_11->text();
    QString prenom = ui->lineEdit_13->text();
    QString date = ui->lineEdit_12->currentText();

    QString diplome = ui->lineEdit_14->currentText();


      Candidat e(CIN,nom,date,prenom,diplome);

      if((ui->lineEdit_11->text()!="")&&(ui->lineEdit_13->text()!="")&&(ui->lineEdit_12->currentText()!="")&&(ui->lineEdit_14->currentText()!="")){
          if((ui->lineEdit_14->currentText()=="EL1")||(ui->lineEdit_14->currentText()=="EL2")||(ui->lineEdit_14->currentText()=="EL3")){
      bool test=e.modifier(CIN,nom,prenom,date,diplome);

      if(test)
    {ui->tableView->setModel(e.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier candidats "),
                      QObject::tr("cadidats modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Modifier un candidat"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }}
      else
      {
              QMessageBox::critical(nullptr, QObject::tr("Modifier un candidat"),
                          QObject::tr("Verifier le champs diplome !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }
      }else {
          QMessageBox::critical(nullptr, QObject::tr("Modifier un candidat"),
                      QObject::tr("Verifier les champs !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
}


void gestioninscription::on_tableView_activated(const QModelIndex &index)
{
    QString val;QSqlQuery query;


        val=ui->tableView->model()->data(index).toString();
       int  x=ui->tableView->model()->data(index).toInt();

         query.prepare("select * from candidats where cin=:x or nom =:val or prenom=:val or datee=:val or diplome=:val ");
         query.bindValue(":val",val);
         query.bindValue(":x",x);

         if (query.exec())
         {
             while (query.next())
             {
                 ui->lineEdit_5->setText(query.value(0).toString());
                 ui->lineEdit_11->setText(query.value(1).toString());
                 ui->lineEdit_13->setText(query.value(2).toString());
                 ui->lineEdit_12->setCurrentText(query.value(3).toString());
                 ui->lineEdit_14->setCurrentText(query.value(4).toString());



             }
         }
         else
         {
             QMessageBox::critical(this ,tr("error::"),query.lastError().text());
         }
}

void gestioninscription::on_pushButton_26_clicked()
{
    widget w;
    w.exec();
}




void gestioninscription::on_lineEdit_rechprenom_cursorPositionChanged(int arg1, int arg2)
{
    Candidat c;
                    QString inputValue,filterChecked;
                    inputValue=ui->lineEdit_rechprenom->text();
                    ui->tableView->setModel(c.rechercherdynamique(inputValue,"prenom"));
}

void gestioninscription::on_lineEdit_rechnom_cursorPositionChanged(int arg1, int arg2)
{
    Candidat c;
                    QString inputValue,filterChecked;
                    inputValue=ui->lineEdit_rechnom->text();
                    ui->tableView->setModel(c.rechercherdynamique(inputValue,"nom"));

}

void gestioninscription::on_pushButton_statis_clicked()
{
    gestioninscription::makePlot_Annee();

}
QVector<double> gestioninscription::Statistique_Annee()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;

    q.prepare("SELECT DATEE FROM CANDIDATS WHERE 2010<DATEE and DATEE<=2015");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT DATEE FROM CANDIDATS WHERE 2015<DATEE and DATEE<=2020");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT DATEE FROM CANDIDATS WHERE 2020<DATEE and DATEE<=2025");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT DATEE FROM CANDIDATS WHERE 2025<DATEE ");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    return stat;
}
void gestioninscription::makePlot_Annee()
{
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, gestioninscription::Statistique_Annee());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot2->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot2->addLayer("abovemain", ui->customPlot2->layer("main"), QCustomPlot::limAbove);
    ui->customPlot2->addLayer("belowmain", ui->customPlot2->layer("main"), QCustomPlot::limBelow);
    ui->customPlot2->xAxis->grid()->setLayer("belowmain");
    ui->customPlot2->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"2010-2015"<<"2015-2020"<<"2020-2025"<<"2025-2030"<<"2030-2035";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot2->xAxis->setTicker(textTicker);
    ui->customPlot2->xAxis->setSubTicks(false);
    ui->customPlot2->xAxis->setTickLength(0,4);
    ui->customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot2->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot2->axisRect()->setBackground(axisRectGradient);

    ui->customPlot2->rescaleAxes();
    ui->customPlot2->xAxis->setRange(0, 7);
    ui->customPlot2->yAxis->setRange(0, 10);


}
void gestioninscription::on_pushButton_opensong_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this,"Selectionner de l'archive ",".mp3");
      reproductor->setMedia(QUrl::fromLocalFile(nombreArchivo));
}

void gestioninscription::on_verticalSlidersong_actionTriggered(int position)
{
    reproductor->setVolume(position);

}

void gestioninscription::showTime()
{
    ui->time->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void gestioninscription::on_comboBox_trier_activated(const QString &arg1)
{
    Candidat c;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="NOM ET PRENOM ET DATEE")
   {
    qry->prepare("Select * from CANDIDATS order by nom,prenom,datee ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
  else if (arg1=="NOM ET PRENOM")
   {
    qry->prepare("Select * from CANDIDATS order by nom,prenom");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

   else if (arg1=="CIN")
   {
    qry->prepare("Select * from CANDIDATS order by cin desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

}

void gestioninscription::on_pushButton_clicked()
{
    A.write_to_arduino("1");//activer le buzzer envoyer 1 à arduino

}

void gestioninscription::on_pushButton_3_clicked()
{
    A.write_to_arduino("0");//déactiver le buzzer envoyer 0 à arduino

}
