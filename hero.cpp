#include "hero.h"

Hero::Hero()
{

}


bool Hero::kill(Monster monster) {
    if(this->inventory == monster.weakness) {
        return true;
    }
    return false;
}
