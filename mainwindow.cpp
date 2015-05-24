#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTimer>

#define BUTTON_WIDTH 20
#define BUTTON_HEIGHT 20

MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setWorld(World* world) {
    timer = new QTimer(this);
    this->world = world;

    pushButtons = new QPushButton*[world->getHeight() * world->getWidth()];
    QPushButton* pushButton;

    for (int i =0;i<world->getHeight();i++)
    {
        for(int j=0;j < world->getWidth();j++)
        {
            pushButton = new QPushButton(ui->widget);
            pushButton->setGeometry(i*BUTTON_HEIGHT, j*BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_WIDTH);
            setButtonColor(pushButton, QString::fromStdString(deathColor));

            pushButton->setProperty("cellPositionX", QVariant(i));
            pushButton->setProperty("cellPositionY", QVariant(j));

            QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(buttonChanged()));
            pushButtons[i * world->getHeight() + j] = pushButton;
        }
    }

    QObject::connect(ui->pushButtonStep, SIGNAL(clicked()), this, SLOT(doStepWorld()));
    QObject::connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(btnClear()));
    QObject::connect(ui->pushButtonRun, SIGNAL(clicked()), this, SLOT(btnRun()));
    QObject::connect(ui->pushButtonStop, SIGNAL(clicked()), this, SLOT(btnStop()));
    QObject::connect(ui->pushButtonRand, SIGNAL(clicked()), this, SLOT(btnRand()));
    setWindowTitle("The World of Empress");
    world->doStep();
    world->doStep();
    updateView();
}

void MainWindow::setButtonColor(QPushButton* pb, QString color) {
    pb->setStyleSheet("QPushButton{background:" + color + ";}" +
                           "QPushButton:hover{background: blue;}");
}

void MainWindow::buttonChanged() {
    int x, y;
    x = QObject::sender() -> property("cellPositionX").toInt();
    y = QObject::sender() -> property("cellPositionY").toInt();
    world->setStatusOfCell(x, y, !world->getStatusOfCell(x, y));

    if (world->getStatusOfCell(x, y))
    {
        setButtonColor(pushButtons[x*world->getHeight() + y], QString::fromStdString(aliveColor));
    }
    else
    {
        setButtonColor(pushButtons[x*world->getHeight() + y], QString::fromStdString(deathColor));
    }
   setLabelAliveNumber();
}

void MainWindow::btnClear()
{
    world->reset();
    updateView();
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
   world->setRandomAlive();
   updateView();
}

void MainWindow::setLabelAliveNumber()
{
   ui -> labelAliveNumber -> setText(QString:: number(world -> getAliveNumber()));
}

void MainWindow::updateView()
{
    for (int x = 0; x < world -> getHeight(); x++) {
        for(int y = 0; y < world -> getWidth(); y++) {
            if (world -> getStatusOfCell(x, y)) {
                setButtonColor(pushButtons[x*world->getHeight() + y], QString::fromStdString(aliveColor));
            }
            else {
                setButtonColor(pushButtons[x*world->getHeight() + y], QString::fromStdString(deathColor));
            }
        }
    }
    setLabelAliveNumber();
}

void MainWindow::doStepWorld()
{
    world->doStep();
    updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
}
