#include "mainwindow.h"
#include <QApplication>
#include "World.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    World world(30, 30);

    MainWindow w;
    w.setWorld(&world);
    w.show();

    return a.exec();
}
