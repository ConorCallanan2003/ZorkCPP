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
    Item *sword = new Item("sword", ":/images/sword.png");
    Item *gun = new Item("gun", ":/images/gun.png");
    Item *gold = new Item("gold", ":/images/gold.png");

    std::vector<Item*> items1 = {sword, gun, gold};
    std::vector<Item*> items2 = {gun, gold, sword};
    std::vector<Item*> items3 = {gold, sword, gun};

    MainWindow w;

    Monster *goblin = new Monster(gold, "goblin", ":/images/goblin.png");
    Monster *demon = new Monster(sword, "demon", ":/images/demon.png");
    Monster *gremlin= new Monster(gun, "gremlin", ":/images/gremlin.png");

    Level::levels.push_back(new Level(":/images/field.png", goblin, items1, "field"));
    Level::levels.push_back(new Level(":/images/graveyard.png", demon, items2, "graveyard"));
    Level::levels.push_back(new Level(":/images/desert.png", gremlin, items3, "desert"));

    w.startDialog1 = new Dialog(&w, new QPointF(100, 0), ":images/expos1.png");
    w.startDialog2 = new Dialog(&w, new QPointF(100, 100), ":images/expos2.png");
    w.setFixedSize(QSize(750, 750));

    w.start();
    a.exec();
    return 0;
}
