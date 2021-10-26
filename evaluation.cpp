#include "evaluation.h"
#include <QSqlQuery>
Evaluation::Evaluation()
{
code=0;
type="";
noteM=0;
noteCl=0;
noteCn=0;
}
Evaluation::Evaluation(int code,QString type,int noteCl,int noteCn,int noteM)
{
this->code=code;
this->type=type;
this->noteCl=noteCl;
this->noteM=noteM;
this->noteCn=noteCn;


}
int Evaluation::getNoteM(){

    return this->noteM;
}
int Evaluation::getNoteCl(){

    return this->noteCl;
}
int Evaluation::getNoteCn(){

    return this->noteCn;
}
QString Evaluation::getType(){

    return this->type;
}
int Evaluation::getCode(){

    return this->code;
}
bool Evaluation::ajouter(){

    QSqlQuery query;
    query.prepare("insert into mycrud values(?,?,?,?,?)");
    query.addBindValue(this->code);
    query.addBindValue(this->noteCl);
    query.addBindValue(this->noteCn);
     query.addBindValue(this->noteM);
     query.addBindValue(this->type);

   return query.exec();
}
bool Evaluation::supprimer(int code){

    QSqlQuery query;
    query.prepare("delete from mycrud where code = ?");
    query.addBindValue(code);


   return query.exec();

}
bool Evaluation::modifier(int a){


    QSqlQuery query;
    query.prepare("update mycrud set note_cn = ? , note_cl = ? , note_m = ? ,  type= ? ,  where code = ?");

    query.addBindValue(this->noteCl);
    query.addBindValue(this->noteCn);
     query.addBindValue(this->noteM);
     query.addBindValue(this->type);
     query.addBindValue(a);




   return query.exec();

}
QSqlQueryModel * Evaluation::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from mycrud");
    //model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));



    return  model;

}


