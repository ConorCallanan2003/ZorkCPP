#ifndef MONSTER_H
#define MONSTER_H
#include "item.h"
#include "avatarwidget.h"

class Monster
{
public:
    Monster(Item *weakness);

    AvatarWidget avatar;

    Item *weakness;
};

#endif // MONSTER_H
