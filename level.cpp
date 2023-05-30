#include "level.h"

Level::Level(std::string mapPath, Monster *monster, std::vector<Item*> items, std::string name)
{
    this->mapPath = mapPath;
    this->monster = monster;
    this->items = items;
    this->name = name;
}

std::vector<Level*> Level::levels = {};

