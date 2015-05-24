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
private:
    World* world;
    QPushButton** pushButtons;
public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    ~MainWindow();
    void setWorld(World* w);

    Ui::MainWindow *ui;

    void setButtonColor(QPushButton* pb, QString color);
    void UpdateView();
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
