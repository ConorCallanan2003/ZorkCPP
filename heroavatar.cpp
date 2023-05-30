#include "heroavatar.h"
#include "monster.h"
#include <QPropertyAnimation>

typedef int (*FuncPtr)(int);

HeroAvatar::HeroAvatar(QWidget *parent, QPointF *startPos, std::string path, Monster *monster, std::vector<Item*> items)
    : AvatarWidget(parent, startPos, path) {
    this->monster = monster;
    this->items = items;
}


bool HeroAvatar::operator==(AvatarWidget *otherAvatar) {
    return overlapping(otherAvatar);
}
