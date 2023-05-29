#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "item.h"

class Level
{
public:
    Level(std::string mapPath, std::string monsterPath, std::vector<Item*> items);

    std::string mapPath;
    std::string monsterPath;
    std::vector<Item*> items;

    static std::vector<Level*> levels;
    static int levelIndex;
};

#endif // LEVEL_H
