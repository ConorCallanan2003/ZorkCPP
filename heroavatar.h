#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "item.h"
#include "monster.h"
//#include "hero.h"


class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", Monster *monster = nullptr, Item *item1 = nullptr, Item *item2 = nullptr, Item *item3 = nullptr);

//    void moveDirection(int x, int y);
    bool overlapping(AvatarWidget *avatar);

    // Move both of these from public and make friend of Hero
//    bool (*killptr)(Monster*);
    Monster *monster;
    Item *item1;
    Item *item2;
    Item *item3;
private:

//    Hero *hero;
};

#endif // HEROAVATAR_H
