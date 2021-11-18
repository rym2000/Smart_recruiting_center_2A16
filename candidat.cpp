 #include "candidat.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
 


Candidat::Candidat()
{
    CIN =0; date=" "; nom=" ";prenom=" ";diplome=" ";
}
Candidat::Candidat(int CIN,QString nom,QString prenom,QString date,QString diplome)
{this->CIN=CIN;this->nom=nom;this->prenom=prenom;this->date=date;this->diplome=diplome ; }
int Candidat::getCIN(){return CIN;}

QString Candidat::getnom (){return nom;}
QString Candidat::getprenom (){return prenom;};
QString Candidat::getdate (){return date;}
QString Candidat::getdiplome (){return diplome;};


        bool Candidat ::ajouter()
        {
            QSqlQuery query;
            query.prepare("insert into candidats values(?,?,?,?,?)");

            query.addBindValue(this->CIN);
                query.addBindValue(this->nom);
                query.addBindValue(this->prenom);
                 query.addBindValue(this->date);
                 query.addBindValue(this->diplome);
                 return query.exec();
        }



    QSqlQueryModel* Candidat::afficher() {
            QSqlQueryModel *model = new QSqlQueryModel();

                model->setQuery("SELECT* FROM candidats");
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
                        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
                        model->setHeaderData(4, Qt::Horizontal, QObject::tr("diplome"));


         return model;



         }

    bool Candidat::supprimer(int CIN)
    {
          QSqlQuery query;
          QString res=QString::number(CIN);
        query.prepare("Delete from candidats where CIN=:CIN");
        query.bindValue(":CIN", res);

        return  query.exec();


    }

     bool Candidat::modifier(int CIN,QString nom,QString prenom,QString date,QString diplome)
     {  QString id_string= QString::number(CIN);

         QSqlQuery query;
            query.prepare(" UPDATE CANDIDATS set CIN=:CIN , NOM=:NOM,PRENOM=:PRENOM ,DATEE=:DATEE, DIPLOME=:DIPLOME  where CIN=:CIN");
            query.bindValue(":CIN",id_string);
                  query.bindValue(":NOM",nom);
                  query.bindValue(":PRENOM",prenom);
                  query.bindValue(":DATEE",date);
                  query.bindValue(":DIPLOME",diplome);
            return query.exec();

     }




        
      
     QSqlQueryModel* Candidat::rechercherdynamique(QString input,QString filter)
     {
         QSqlQueryModel * model= new QSqlQueryModel ();
            QSqlQuery query;
            query.prepare("SELECT * FROM CANDIDATS WHERE "+filter+" LIKE '%' || :inputValue || '%' ");
            query.bindValue(":inputValue",input);
            query.exec();
            model->setQuery(query);
            return model;
     }
