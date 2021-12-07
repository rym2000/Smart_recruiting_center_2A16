#include "entretien.h"
#include <QSqlQuery>

Entretien::Entretien()
{
Num=0;
Lieu="";
Numposte=0;
DateE="";
}
Entretien::Entretien(int Num,QString Lieu,int Numposte,QString DateE)
{
this->Num=Num;
this->Lieu=Lieu;
this->Numposte=Numposte;
this->DateE=DateE;


}
int Entretien::getNumposte(){

    return this->Numposte;
}
QString Entretien::getDateE(){

    return this->DateE;
}
QString Entretien::getLieu(){

    return this->Lieu;
}
int Entretien::getNum(){

    return this->Num;
}
void Entretien::setNum(int Num){this->Num=Num;}
void Entretien::setnump(int Numposte){this->Numposte=Numposte;}
void Entretien::setlieu(QString Lieu){this->Lieu=Lieu;}
void Entretien ::setdate(QString DateE){this->DateE=DateE;}
bool Entretien::ajouter(){
    QSqlQuery query;
    QString numpost_string= QString::number(Numposte);
        QString Num_string= QString::number(Num);
              query.prepare("INSERT INTO TABLE1 (Num, Datee, Lieu, Numposte) "
                            "VALUES (:Num, :DateE, :Lieu, :Numposte)");
                        query.bindValue(0, Num_string);
                        query.bindValue(1, DateE);
                        query.bindValue(2, Lieu);
                        query.bindValue(3,numpost_string);
   return query.exec();
}
bool Entretien::supprimer(int Num){

    QSqlQuery query;
     QString Num_string= QString::number(Num);
    query.prepare("delete from TABLE1 where Num =:Num");
    query.addBindValue(Num_string);


   return query.exec();

}
bool Entretien::modifier(int Num,int Numposte, QString Lieu,QString DateE){


    QSqlQuery query;
         QString Num_string= QString::number(Num);
         QString Numposte_string= QString::number(Numposte);
           query.prepare(" UPDATE TABLE1 set Num=:Num ,Datee=:DateE,Lieu=:Lieu ,Numposte=:Numposte where Num=:Num");
           query.bindValue(":Num",Num_string);
           query.bindValue(":Numposte",Numposte_string);
           query.bindValue(":Lieu",Lieu);
           query.bindValue(":DateE",DateE);



   return query.exec();

}
QSqlQueryModel * Entretien::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TABLE1");



    return  model;

}
QSqlQueryModel* Entretien::triNum()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM TABLE1 ORDER BY NUM ");
           return model;
}
QSqlQueryModel* Entretien::triNumposte()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM TABLE1 ORDER BY LIEU");
           return model;
}

void Entretien :: rechercher(QTableView * TABLE1 ,int Num ,int Numposte)
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        QString  Num_string  =QString::number(Num);
        QString  Numposte_string  =QString::number(Numposte);


        query->prepare("select * FROM TABLE1 where NUM like '%"+Num_string+"%' or Numposte like '%"+Numposte_string+"%' ;");


        query->exec();
        model->setQuery(*query);
        TABLE1->setModel(model);
        TABLE1->show();

    }
