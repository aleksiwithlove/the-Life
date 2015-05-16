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

    ~MainWindow();
    void setWorld(World* w);

    World* world;
    Ui::MainWindow *ui;
    QPushButton* doStep;
    QPushButton** pushButtons;
    void setButtonColor(QPushButton* pb, QString color);
    void UpdateView();

public slots:
    void buttonChanged();
    void do_step();
};

#endif // MAINWINDOW_H
