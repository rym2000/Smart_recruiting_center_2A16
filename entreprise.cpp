#include "entreprise.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QPainter>

#include <QSqlTableModel>
#include <QPagedPaintDevice>

Entreprise::Entreprise()
{

        delai=0;
        identifiant = 0 ;
        nom = "";
        offre= "";
    }
    Entreprise::Entreprise ( int identifiant , QString nom , QString offre , int delai , QString adresse_mail)
    {
        this->identifiant=identifiant;
        this->nom=nom;
        this->offre=offre;
        this->delai=delai;
        this->adresse_mail=adresse_mail;
      }

   int Entreprise::getidentifiant() { return identifiant ;}
  QString Entreprise::getnom() { return nom ;}
  QString Entreprise::getoffre() { return offre ;}
  int Entreprise::getdelai() { return delai ;}
  QString Entreprise::getadresse_mail() { return adresse_mail ;}
    void Entreprise::setidentifiant(int identifiant ){this->identifiant= identifiant;}
     void Entreprise::setnom(QString nom ){this->nom=nom;}
     void Entreprise::setoffre(QString offre ){this->offre=offre;}
     void Entreprise::setdelai( int delai ){this->delai=delai;}
     void Entreprise::setadresse_mail(QString adresse_mail ){this->adresse_mail=adresse_mail;}


   bool Entreprise::ajouter()
   {


        QString  identifiant_string  =QString::number(identifiant);
        QString  delai_string   =QString::number(delai);
        QSqlQuery query;

          query.prepare("INSERT INTO ENTREPRISE (identifiant, nom, offre, delai, adresse_mail)"
                        "VALUES (:identifiant ,:nom ,:offre ,:delai ,:adresse_mail)") ;



          query.bindValue(":identifiant", identifiant_string );
          query.bindValue(":nom", nom);
          query.bindValue(":offre", offre);
           query.bindValue(":delai", delai_string );
           query.bindValue(":adresse_mail", adresse_mail);

           return query.exec();



    }
    QSqlQueryModel* Entreprise::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();


              model->setQuery("SELECT* FROM ENTREPRISE");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("offre"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("delai"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_mail"));
    return model ;
    }
    bool Entreprise::supprimer(int identifiant)
    { QSqlQuery query;
        QString res=QString::number(identifiant);
      query.prepare("Delete from ENTREPRISE where identifiant=:identifiant");
      query.bindValue(":identifiant", res);

      return  query.exec();
    }

    bool Entreprise::modifier( int identifiant , QString nom , QString offre , int delai , QString adresse_mail )

    {
        QSqlQuery query;
        QString  identifiant_string  =QString::number(identifiant);
        QString  delai_string   =QString::number(delai);
           query.prepare("UPDATE ENTREPRISE SET identifiant=:identifiant,nom=:nom,offre=:offre,delai=:delai,adresse_mail=:adresse_mail WHERE identifiant=:identifiant");
           query.bindValue(":identifiant", identifiant_string);
           query.bindValue(":nom",nom);
           query.bindValue(":offre",offre);
           query.bindValue(":delai",delai_string );
            query.bindValue(":adresse_mail",adresse_mail);

           return query.exec();
    }



    QSqlQueryModel * Entreprise::trier()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM ENTREPRISE ORDER BY delai ");
            return model;
    }
    QSqlQueryModel * Entreprise::trier1()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM ENTREPRISE ORDER BY nom ");
            return model;
    }
    QSqlQueryModel * Entreprise::trier2()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM ENTREPRISE ORDER BY offre ");
            return model;
    }








    void Entreprise :: rechercher(QTableView * table ,int identifiant , QString nom,QString offre )
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        QString  id_string  =QString::number(identifiant);
        query->prepare("select * from ENTREPRISE where IDENTIFIANT like '%"+id_string+"%' or NOM like '%"+nom+"%' or OFFRE like '%"+offre+"%' ;");


        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();

    }


