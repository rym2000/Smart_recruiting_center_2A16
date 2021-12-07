#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"gestioninscription.h"
#include "entreprises.h"
#include "entretienn.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_gestioninscription_clicked();

    void on_gestioninscription_5_clicked();

    void on_gestioninscription_2_clicked();

private:
    Ui::menu *ui;
    gestioninscription *ginscrition;
    entreprises *Entreprise;
    entretienn *entr ;

};

#endif // MENU_H
