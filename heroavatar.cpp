#include "heroavatar.h"
#include "monster.h"
#include <QPropertyAnimation>

typedef int (*FuncPtr)(int);

HeroAvatar::HeroAvatar(QWidget *parent, QPointF *startPos, std::string path, Monster *monster, std::vector<Item*> items)
    : AvatarWidget(parent, startPos, path) {
    this->monster = monster;
    this->items = items;
}



bool HeroAvatar::overlapping(AvatarWidget *avatar) {

    int hx = pos().x() + (width()/2);
    int hy = pos().y() + (height()/2);

    int ax = avatar->pos().x() + (avatar->width()/2);
    int ay = avatar->pos().y() + (avatar->height()/2);

    if (hx < (ax+150) && hx > (ax-150)) {
        if (hy < (ay+150) && hy > (ay-150)) {
            return true;
        }
    }
    return false;

}
