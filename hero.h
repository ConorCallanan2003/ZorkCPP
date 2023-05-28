#ifndef HERO_H
#define HERO_H
#include "item.h"
#include "monster.h"
#include "heroavatar.h"


class Hero
{
public:
    Hero(/*HeroAvatar *avatar*/);

    HeroAvatar *avatar;

    Item *inventory;

    bool kill(Monster *monster);

    void take(Item *item);

    void moveDirection(int x, int y);
};

#endif // HERO_H
