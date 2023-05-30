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

    Monster *monster;
    std::vector<Item*> items;
    std::string name;

    static std::vector<Level*> levels;
//    static int levelIndex;

private:
    std::string mapPath;


    friend class MainWindow;
};

#endif // LEVEL_H
