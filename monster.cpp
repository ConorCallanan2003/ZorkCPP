#include "monster.h"
#include "avatarwidget.h"

Monster::Monster(Item *weakness, std::string name, std::string path)
{
    this->weakness = weakness;
    this->name = name;
    this->dead = false;
    this->path = path;
}
