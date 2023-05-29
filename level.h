#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "item.h"

class Level
{
public:
    Level(std::string mapPath, std::string monsterPath, Item *item1 = nullptr, Item *item2 = nullptr, Item *item3 = nullptr);

    std::string mapPath;
    std::string monsterPath;
    Item *item1;
    Item *item2;
    Item *item3;

    static std::vector<Level> levels;
    static int levelIndex;
};

#endif // LEVEL_H
