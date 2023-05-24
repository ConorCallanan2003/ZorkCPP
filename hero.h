#ifndef HERO_H
#define HERO_H
#include "item.h"
#include "monster.h"
#include "heroavatar.h"


class Hero
{
public:
    Hero(HeroAvatar *avatar);

    HeroAvatar *avatar;

    Item *inventory;

    bool kill(Monster *monster);
};

#endif // HERO_H
