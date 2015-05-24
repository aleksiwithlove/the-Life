#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "World.h"
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    World* world;
    QPushButton** pushButtons;
    Ui::MainWindow *ui;
    QTimer *timer;
    const std::string aliveColor = "green";
    const std::string deathColor = "red";

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setWorld(World* w);
    void setButtonColor(QPushButton* pb, QString color);
    void updateView();
    void setLabelAliveNumber();

public slots:
    void buttonChanged();
    void doStepWorld();
    void btnClear();
    void btnRun();
    void btnStop();
    void btnRand();
};

#endif // MAINWINDOW_H
