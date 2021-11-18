#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 #include "candidat.h"
#include <QMainWindow>
#include "gestioninscription.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_gestioninscription_clicked();

private:
    Ui::MainWindow *ui;
    gestioninscription *ginscrition;

};
#endif // MAINWINDOW_H
