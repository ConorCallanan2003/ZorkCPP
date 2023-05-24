#include "hero.h"

Hero::Hero(HeroAvatar *avatar)
{
    this->avatar = avatar;
}


bool Hero::kill(Monster *monster) {
    if(this->inventory == monster->weakness) {
        return true;
    }
    return false;
}
