#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "item.h"
#include "monster.h"

class Level
{
public:
    Level(std::string mapPath, Monster *monster, std::vector<Item*> items, std::string name);

    std::string mapPath;
    Monster *monster;
    std::vector<Item*> items;
    std::string name;

    static std::vector<Level*> levels;
    static int levelIndex;
};

#endif // LEVEL_H
