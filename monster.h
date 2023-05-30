#ifndef MONSTER_H
#define MONSTER_H
#include "item.h"
#include "avatarwidget.h"
#include "living.h"

class Monster : public Thing, public Living
{
public:
    Monster(Item *weakness, std::string name, std::string path);

    AvatarWidget *avatar;
    Item *weakness;
    std::string path;
};

#endif // MONSTER_H
