#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"gestioninscription.h"

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

private:
    Ui::menu *ui;
    gestioninscription *ginscrition;

};

#endif // MENU_H
