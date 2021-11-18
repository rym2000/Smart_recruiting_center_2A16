#ifndef GESTIONINSCRIPTION_H
#define GESTIONINSCRIPTION_H
#include "candidat.h"

#include <QDialog>
#include <QMediaPlayer>
#include"QDate"

namespace Ui {
class gestioninscription;
}

class gestioninscription : public QDialog
{
    Q_OBJECT

public:
    explicit gestioninscription(QWidget *parent = nullptr);
    ~gestioninscription();

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();


    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_26_clicked();
    void on_pushButton_statis_clicked();


    void on_lineEdit_rechprenom_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_rechnom_cursorPositionChanged(int arg1, int arg2);
    void makePlot_Annee ();
        QVector<double> Statistique_Annee();

    void on_pushButton_opensong_clicked();
    void on_verticalSlidersong_actionTriggered(int action);
    void showTime();
    void on_comboBox_trier_activated(const QString &arg1);




private:
    Ui::gestioninscription *ui;
    Candidat c ;

    QMediaPlayer        *reproductor;


};

#endif // GESTIONINSCRIPTION_H
