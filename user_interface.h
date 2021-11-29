#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "employe.h"
#include <QMainWindow>

namespace Ui {
class user_interface;
}

class user_interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_interface(QWidget *parent = nullptr);
    ~user_interface();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::user_interface *ui;
    employe e;
};

#endif // USER_INTERFACE_H
