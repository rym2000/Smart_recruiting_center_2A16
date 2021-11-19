#ifndef EVALUATION_H
#define EVALUATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QPdfWriter>
#include <QPainter>
class Evaluation
{
public:
    QString type;
    int code,noteCl,noteCn,noteM;
public:
    Evaluation();
    Evaluation(int,QString,int,int,int);
    int getCode();
    QString getType();
    int getNoteCl();
    int getNoteCn();
    int getNoteM();
    bool ajouter();
    //QSqlQueryMod
    bool supprimer(int);
    bool modifier(int);
    QStandardItemModel* afficher(QObject* parent);
    QSqlQueryModel * afficherCode();
    QStandardItemModel * recherche(const QString &arg1,QObject *parent);
    QStandardItemModel* trier(QObject* parent,int in);
    void telechargerPDF();





};

#endif // EVALUATION_H
