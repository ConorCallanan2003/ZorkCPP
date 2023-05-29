#include "level.h"

Level::Level(std::string mapPath, std::string monsterPath, Item *item1, Item *item2, Item *item3)
{
    this->mapPath = mapPath;
    this->monsterPath = monsterPath;
    this->item1 = item1;
    this->item2 = item2;
    this->item3 = item3;
}

//Level *level1 = new Level(":/images/desert.png", ":/images/gremlin.png", ":/images/gold.png", new Item("Gold"));
//Level *level2 = new Level(":/images/field.png", ":/images/goblin.png", ":/images/sword.png", new Item("Sword"));

std::vector<Level> Level::levels = {Level(":/images/field.png", ":/images/goblin.png", new Item("Sword", ":/images/sword.png"), new Item("Gold", ":/images/gold.png"), new Item("Gun", ":/images/gun.png")), Level(":/images/graveyard.png", ":/images/demon.png", new Item("Gun", ":/images/gun.png"), new Item("Gold", ":/images/gold.png"), new Item("Sword", ":/images/sword.png")), Level(":/images/field.png", ":/images/goblin.png", new Item("Gun", ":/images/gun.png"), new Item("Gold", ":/images/gold.png"), new Item("Sword", ":/images/sword.png"))};
int Level::levelIndex = 0;

