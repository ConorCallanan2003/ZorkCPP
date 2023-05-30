#include "monster.h"
#include "avatarwidget.h"

Monster::Monster(Item *weakness, std::string name, std::string path) : Thing(name), Living()
{
    this->weakness = weakness;
    this->path = path;
}
