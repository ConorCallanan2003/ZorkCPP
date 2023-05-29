#include "mainwindow.h"
#include "item.h"
#include "level.h"

#include <QApplication>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
//#include <QBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::vector<Item*> items1 = {new Item("Sword", ":/images/sword.png"), new Item("Gold", ":/images/gold.png"), new Item("Gun", ":/images/gun.png")};
    std::vector<Item*> items2 = {new Item("Gun", ":/images/gun.png"), new Item("Gold", ":/images/gold.png"), new Item("Sword", ":/images/sword.png")};
    std::vector<Item*> items3 = {new Item("Gun", ":/images/gun.png"), new Item("Gold", ":/images/gold.png"), new Item("Sword", ":/images/sword.png")};
    //std::vector<*Item> items4 = {new Item("Gun", ":/images/gun.png"), new Item("Gold", ":/images/gold.png"), new Item("Sword", ":/images/sword.png")};

    Level::levels.push_back(new Level(":/images/field.png", ":/images/goblin.png", items1));
    Level::levels.push_back(new Level(":/images/graveyard.png", ":/images/demon.png", items2));
    Level::levels.push_back(new Level(":/images/field.png", ":/images/goblin.png", items3));

    MainWindow w;

    w.startDialog1 = new Dialog(&w, new QPointF(100, 0), ":images/expos1.png");
    w.startDialog2 = new Dialog(&w, new QPointF(100, 100), ":images/expos2.png");
    w.setFixedSize(QSize(750, 750));

    w.start();
    a.exec();
    return 0;
}
