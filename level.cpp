#include "level.h"

Level::Level(std::string mapPath, std::string monsterPath, std::vector<Item*> items)
{
    this->mapPath = mapPath;
    this->monsterPath = monsterPath;
    this->items = items;
}

//Level *level1 = new Level(":/images/desert.png", ":/images/gremlin.png", ":/images/gold.png", new Item("Gold"));
//Level *level2 = new Level(":/images/field.png", ":/images/goblin.png", ":/images/sword.png", new Item("Sword"));


std::vector<Level*> Level::levels = {};
int Level::levelIndex = 0;

