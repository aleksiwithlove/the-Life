#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QTimer>
#include <stdlib.h>     /* srand, rand */
#include <sstream>
//#include "World.h"
MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::setWorld(World* world) {
    timer = new QTimer(this);

    this->world = world;
    pushButtons = new QPushButton*[20 * 20];
    QPushButton* pushButton;
    for (int i =0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            pushButton = new QPushButton(ui->widget);
            pushButton->setGeometry(i*20, j*20, 20, 20);
            setButtonColor(pushButton, "red");

            pushButton->setProperty("cellPositionX", QVariant(i));
            pushButton->setProperty("cellPositionY", QVariant(j));

            QObject::connect(pushButton, SIGNAL(clicked()),
                             this, SLOT(buttonChanged()));
            pushButtons[i * 20 + j] = pushButton;
        }
    }

    QObject::connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(do_step()));
    QObject::connect(ui->pushButton_10,SIGNAL(clicked()), this, SLOT(btn_reset()));

    QObject::connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(btn_run()));
    QObject::connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(btn_stop()));
    QObject::connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(btn_rand()));
    QObject::connect(ui->label_4,SIGNAL(MyS())), this, SLOT(lbl_num());

    setWindowTitle("The World of Empress");

    UpdateView();
}

void MainWindow::setButtonColor(QPushButton* pb, QString color) {
    pb->setStyleSheet("QPushButton{background:" + color + ";}"
                           "QPushButton:hover{background: blue;}");
}

void MainWindow::buttonChanged() {
    int x, y;
    x = QObject::sender()->property("cellPositionX").toInt();
    y = QObject::sender()->property("cellPositionY").toInt();
    //std::cout << x << " " << y << std::endl;

    world->setStatusOfCell(x, y, !world->getStatusOfCell(x, y));
    if (world->getStatusOfCell(x, y)) {
        setButtonColor(pushButtons[x*20 + y], "green");
    }
    else {
        setButtonColor(pushButtons[x*20 + y], "red");
    }
}

void MainWindow::btn_reset()
{
    world->reset();
    UpdateView();
}

void MainWindow::btn_run()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(do_step()));
    timer->start(1000);
}

void MainWindow::btn_stop()
{
    timer->stop();
}

void MainWindow::btn_rand()
{
    for (int i; i < world->height; i++)
    {
        for(int j; j < world->width; j++)
        {
            int z = std::rand()%2;
            std::cout << z;
            world->setStatusOfCell(i,j,z);
        }
    }
    UpdateView();
}

void MainWindow::lbl_num()
{
    std::stringstream s;

    int sum = 0;
    for (int i; i < world->height; i++)
    {
        for(int j; j < world->width; j++)
        {
            sum += world->getStatusOfCell(i,j)? 1 : 0;
        }
    }

    s << sum;
    ui->label_4->setText(s);
}

void MainWindow::MyS()
{
    if (0 == 0) emit MyS();
}

void MainWindow::UpdateView()
{
    for (int x =0;x<20;x++) {
        for(int y=0;y<20;y++) {
            if (world->getStatusOfCell(x, y)) {
                setButtonColor(pushButtons[x*20 + y], "green");
            }
            else {
                setButtonColor(pushButtons[x*20 + y], "red");
            }
        }
    }
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
