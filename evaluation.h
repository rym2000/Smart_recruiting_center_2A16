#ifndef EVALUATION_H
#define EVALUATION_H
#include <QString>
#include <QSqlQueryModel>
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
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);

};

#endif // EVALUATION_H
