#include "mainwindow.h"
#include "item.h"

#include <QApplication>
#include <string>
#include <vector>
//#include <QBrowser>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setFixedSize(QSize(750, 750));
//    w.runGame(":/images/field.png", ":/images/goblin.png", ":/images/sword.png", new Item("Sword"), &game2);

    w.start();

    return a.exec();
}
