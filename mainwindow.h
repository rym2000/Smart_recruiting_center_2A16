#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QtDebug>

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

    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    menu *Menu;
    QPropertyAnimation *animation,*animationimg;
};
#endif // MAINWINDOW_H
