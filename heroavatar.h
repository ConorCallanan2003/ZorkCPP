#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "item.h"
#include "monster.h"
//#include "hero.h"

class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", Monster *monster = nullptr, Item *item1 = nullptr/*, Hero *hero*/);

    void moveDirection(int x, int y);
    bool overlapping(AvatarWidget *avatar);
private:
    Monster *monster;
    Item *item1;
//    Hero *hero;
};

#endif // HEROAVATAR_H
