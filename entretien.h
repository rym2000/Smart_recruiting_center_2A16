#ifndef ENTRETIEN_H
#define ENTRETIEN_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>
class Entretien
{
public:
    QString Lieu,DateE;
    int Num,Numposte;

public:
    Entretien();
    Entretien(int,QString,int,QString);
    int getNum();
    int getNumposte();
    QString getLieu();
    QString getDateE();
    void setNum(int);
        void setnump(int);
        void setlieu(QString);
        void setdate(QString);
        void on_trier_num_clicked();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * triNom();
    QSqlQueryModel * triNum();
    QSqlQueryModel * triNumposte();
           void rechercher(QTableView * TABLE1,int,int);
    bool supprimer(int);
    bool modifier(int,int,QString,QString);



};

#endif // ENTRETIEN_H
