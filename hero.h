#ifndef HERO_H
#define HERO_H
#include "item.h"
#include "monster.h"


class Hero
{
public:
    Hero();

    Item *inventory;

    bool kill(Monster monster);
};

#endif // HERO_H
