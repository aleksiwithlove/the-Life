#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include "World.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //MainWindow(World* w, QWidget *parent = 0);
    QTimer *timer;

    ~MainWindow();
    void setWorld(World* w);

    World* world;
    Ui::MainWindow *ui;
    QPushButton* doStep;
    QPushButton** pushButtons;
    void setButtonColor(QPushButton* pb, QString color);
    void UpdateView();
signals:
    void MyS();

public slots:
    void buttonChanged();
    void do_step();
    void btn_reset();
    void btn_run();
    void btn_stop();
    void btn_rand();
    void lbl_num();
};

#endif // MAINWINDOW_H
