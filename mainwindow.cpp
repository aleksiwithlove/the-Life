#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QTimer>
#include <sstream>
MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::setWorld(World* world) {
    timer = new QTimer(this);

    this->world = world;
    pushButtons = new QPushButton*[world->WorldHeight() * world->WorldWidth()];
    QPushButton* pushButton;
    for (int i =0;i<world->WorldHeight();i++)
    {
        for(int j=0;j < world->WorldWidth();j++)
        {
            pushButton = new QPushButton(ui->widget);
            pushButton->setGeometry(i*20, j*20, 20, 20);
            setButtonColor(pushButton, "red");

            pushButton->setProperty("cellPositionX", QVariant(i));
            pushButton->setProperty("cellPositionY", QVariant(j));

            QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(buttonChanged()));
            pushButtons[i * world->WorldHeight() + j] = pushButton;
        }
    }

    QObject::connect(ui->pushButtonStep,SIGNAL(clicked()), this, SLOT(doStepWorld()));
    QObject::connect(ui->pushButtonClear,SIGNAL(clicked()), this, SLOT(btnClear()));

    QObject::connect(ui->pushButtonRun,SIGNAL(clicked()), this, SLOT(btnRun()));
    QObject::connect(ui->pushButtonStop,SIGNAL(clicked()), this, SLOT(btnStop()));
    QObject::connect(ui->pushButtonRand,SIGNAL(clicked()), this, SLOT(btnRand()));

    setWindowTitle("The World of Empress");
    world->doStep();
    world->doStep();

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

  world->setStatusOfCell(x, y, !world->getStatusOfCell(x, y));
    if (world->getStatusOfCell(x, y)) {
        setButtonColor(pushButtons[x*world->WorldHeight() + y], "green");
    }
    else {
        setButtonColor(pushButtons[x*world->WorldHeight() + y], "red");
    }
   setLabelAliveNumber();
}

void MainWindow::btnClear()
{
    world->reset();
    UpdateView();
 }

void MainWindow::btnRun()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(doStepWorld()));
    timer->start(500);
}

void MainWindow::btnStop()
{
    timer->stop();
}

void MainWindow::btnRand()
{
    for (int i = 0; i < world->WorldHeight(); i++)
    {
        for(int j = 0; j < world->WorldWidth(); j++)
        {
            int z = std::rand()%2;
            world->setStatusOfCell(i, j, (bool) z);
        }
    }
    UpdateView();
}

void MainWindow::setLabelAliveNumber()
{
    int sum = 0;
    for (int i = 0; i < world->WorldHeight(); i++)
    {
        for(int j = 0; j < world->WorldWidth(); j++)
        {
            sum += world->getStatusOfCell(i,j)? 1 : 0;
        }
    }

    ui->labelAliveNumber->setText(QString::number(sum));
}

void MainWindow::UpdateView()
{
    for (int x =0;x<world->WorldHeight();x++) {
        for(int y=0;y<world->WorldWidth();y++) {
            if (world->getStatusOfCell(x, y)) {
                setButtonColor(pushButtons[x*world->WorldHeight() + y], "green");
            }
            else {
                setButtonColor(pushButtons[x*world->WorldHeight() + y], "red");
            }
        }
    }
    setLabelAliveNumber();
}

void MainWindow::doStepWorld()
{
    world->doStep();
    UpdateView();
}

MainWindow::~MainWindow()
{
    delete ui;
}
