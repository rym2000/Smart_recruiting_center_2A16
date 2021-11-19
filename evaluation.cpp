#include "evaluation.h"
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
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
    query.prepare("insert into mycrud values( :code, :notecl, :notecn, :notem, :type)");
    query.bindValue(":code", code);
    query.bindValue(":notecl", noteCl);
    query.bindValue(":notecn", noteCn);
    query.bindValue(":notem", noteM);
    query.bindValue(":type", type);
    return  query.exec();

}
bool Evaluation::supprimer(int code){

    QSqlQuery query;
    query.prepare("delete from mycrud where code = ?");
    query.addBindValue(code);


   return query.exec();

}
bool Evaluation::modifier(int code){


}
/*QSqlQueryModel * Evaluation::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from mycrud");



    return  model;

}*/
QStandardItemModel* Evaluation::afficher(QObject* parent){


    QSqlQuery q;
    q.prepare("select count(*) from mycrud;");
     int i=0;
     if(q.exec()){
         while(q.next()){
                 i=q.value(0).toInt();

             }





     }

      QStandardItemModel* model =new QStandardItemModel(i,5,parent);
  // QSqlQueryModel *model1=new QSqlQueryModel();

    //QStandardItemModel* model =new QStandardItemModel(4,2,this);

    q.prepare("select * from mycrud");
     i=0;
     if(q.exec()){
         while(q.next()){
             for(int col=0; col<5 ; col++){
                 QString a=q.value(col).toString();
                 QModelIndex index=model->index(i,col,QModelIndex());
                 model->setData(index,a);
             }



             i++;
         }
     }
   return model;



}
QSqlQueryModel *Evaluation::afficherCode(){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select code from mycrud");



    return  model;



}
QStandardItemModel *Evaluation::recherche(const QString &arg1,QObject *parent){
    QSqlQuery q;
    q.prepare("select count(*) from mycrud;");
     int i=0;
     if(q.exec()){
         while(q.next()){
                 i=q.value(0).toInt();

             }





     }

      QStandardItemModel* model =new QStandardItemModel(i,5,parent);
  // QSqlQueryModel *model1=new QSqlQueryModel();

    //QStandardItemModel* model =new QStandardItemModel(4,2,this);
    i=0;
    q.prepare("select * from mycrud where code like :q");
    q.bindValue(":q","%"+arg1+"%");
    if(q.exec()){
        while(q.next()){
            for (int col=0;col<5;col++){
                QString a=q.value(col).toString();
                QModelIndex index=model->index(i,col,QModelIndex());
                model->setData(index,a);

            }
            i++;
        }

     }
   return model;




}
QStandardItemModel* Evaluation::trier(QObject* parent,int in){
    QString tri[4]={"code","note_cn","note_cl","note_m"};
    QSqlQuery q;
    q.prepare("select count(*) from mycrud;");
     int i=0;
     if(q.exec()){
         while(q.next()){
                 i=q.value(0).toInt();

             }





     }

      QStandardItemModel* model =new QStandardItemModel(i,5,parent);
  // QSqlQueryModel *model1=new QSqlQueryModel();

    //QStandardItemModel* model =new QStandardItemModel(4,2,this);
    i=0;
    if(in==0){
        q.prepare("select * from mycrud order by code");

    }
    if(in==1){
        q.prepare("select * from mycrud order by note_cn");

    }
    if(in==2){
        q.prepare("select * from mycrud order by note_cl");

    }
    if(in==3){
        q.prepare("select * from mycrud order by note_m");

    }





    if(q.exec()){


        while(q.next()){
            for (int col=0;col<5;col++){
                QString a=q.value(col).toString();
                QModelIndex index=model->index(i,col,QModelIndex());
                model->setData(index,a);

            }
            i++;
        }

     }
   return model;




}
void  Evaluation::telechargerPDF(){


                     QPdfWriter pdf("C:\\Users\\ASUS\\OneDrive\\Bureau\\export_pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"ENTRETIENT");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"CODE");
                         painter.drawText(1300,3300,"NOTE_CL");
                         painter.drawText(2200,3300,"NOTE_CN");
                         painter.drawText(3200,3300,"NOTE_M");
                         painter.drawText(5300,3300,"TYPE");


                         QSqlQuery query;
                         //query.prepare("select * from mycrud where code='"+val+"'");
                         query.prepare("select * from mycrud");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(2).toString());
                             painter.drawText(2200,i,query.value(3).toString());
                             painter.drawText(3200,i,query.value(1).toString());
                             painter.drawText(5300,i,query.value(4).toString());




                            i = i + 500;
                         }}





