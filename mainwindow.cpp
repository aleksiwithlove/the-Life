#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
//#include "World.h"

MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::setWorld(World* world) {
    this->world = world;
    pushButtons = new QPushButton*[20 * 20];
    QPushButton* pushButton;
    for (int i =0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            pushButton = new QPushButton(ui->centralWidget);
            pushButton->setGeometry(i*20, j*20, 20, 20);
            setButtonColor(pushButton, "red");

            pushButton->setProperty("cellPositionX", QVariant(i));
            pushButton->setProperty("cellPositionY", QVariant(j));

            QObject::connect(pushButton, SIGNAL(clicked()),
                             this, SLOT(buttonChanged()));
            pushButtons[i * 20 + j] = pushButton;
        }
    }

    doStep = new QPushButton(ui->centralWidget);
    doStep->setGeometry(500, 200, 60,60);
    QObject::connect(doStep,SIGNAL(clicked()), this, SLOT(do_step()));

    setWindowTitle("The World of Empress");
    setMinimumHeight(400);
    setMinimumWidth(600);

}

void MainWindow::setButtonColor(QPushButton* pb, QString color) {
    pb->setStyleSheet("QPushButton{background:" + color + ";}"
                           "QPushButton:hover{background: blue;}");
}

void MainWindow::buttonChanged() {
    int x, y;
    x = QObject::sender()->property("cellPositionX").toInt();
    y = QObject::sender()->property("cellPositionY").toInt();
    std::cout << x << " " << y << std::endl;
    world->setStatusOfCell(x, y, !world->getStatusOfCell(x, y));
    if (world->getStatusOfCell(x, y)) {
        setButtonColor(pushButtons[x*20 + y], "green");
    } else {
        setButtonColor(pushButtons[x*20 + y], "red");
    }
}
void MainWindow::UpdateView()
{

}

void MainWindow::do_step()
{
    world->doStep();
    UpdateView();
}



MainWindow::~MainWindow()
{
    delete ui;
}
