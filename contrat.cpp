#include "contrat.h"

contrat::contrat()
{

}
contrat::contrat(int id,QString nom,QString prenom,float duree,QString type,int id_candidat,int id_entreprise)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->duree=duree;
    this->type=type;
    this->id_entreprise=id_entreprise;
    this->id_candidat=id_candidat;
}
bool contrat::ajouter()
{
    QString d=QString::number(duree);
   QSqlQuery q;
   q.prepare("insert into contrat(id,nom,prenom,duree,type,id_candidat,id_entreprise) VALUES(:id,:nom,:prenom,:duree,:type,:id_candidat,:id_entreprise)");//preparation du requete
   q.bindValue(":id",id);//injection sql srcurité
   q.bindValue(":nom",nom);
   q.bindValue(":prenom",prenom);
   q.bindValue(":duree",d);
   q.bindValue(":type",type);
   q.bindValue(":id_candidat",id_candidat);
   q.bindValue(":id_entreprise",id_entreprise);
   return q.exec();//execution du requete
}
bool contrat::modifier(int id)
{
      QString d=QString::number(duree);
    QSqlQuery q;
    q.prepare("update contrat set nom=:nom,prenom=:prenom,duree=:duree,type=:type,id_entreprise=:id_entreprise,id_candidat=:id_candidat where id=:id");//preparation du requete
    q.bindValue(":id",id);//injection sql srcurité
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":duree",d);
    q.bindValue(":type",type);
    q.bindValue(":id_candidat",id_candidat);
    q.bindValue(":id_entreprise",id_entreprise);
    return q.exec();//execution du requete
}
bool contrat::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from contrat where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}
QSqlQueryModel* contrat::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from contrat");
    return model;
}
QSqlQueryModel* contrat::trier(QString type)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from contrat order by "+type);
    return model;
}
