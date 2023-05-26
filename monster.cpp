#include "monster.h"
#include "avatarwidget.h"

Monster::Monster(Item *weakness, AvatarWidget *avatar)
{
    this->weakness = weakness;
    this->avatar = avatar;
    this->dead = false;
}
