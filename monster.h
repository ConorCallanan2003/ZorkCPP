#ifndef MONSTER_H
#define MONSTER_H
#include "item.h"
#include "avatarwidget.h"

class Monster
{
public:
    Monster(Item *weakness, AvatarWidget *avatar);

    AvatarWidget *avatar;

    bool dead;

    Item *weakness;
};

#endif // MONSTER_H
