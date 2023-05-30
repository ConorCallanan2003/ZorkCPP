#ifndef MONSTER_H
#define MONSTER_H
#include "item.h"
#include "avatarwidget.h"

class Monster
{
public:
    Monster(Item *weakness, std::string name, std::string path);

    AvatarWidget *avatar;
    bool dead;
    std::string name;
    Item *weakness;
    std::string path;
};

#endif // MONSTER_H
