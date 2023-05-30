#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "item.h"
#include "monster.h"
//#include "hero.h"


class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", Monster *monster = nullptr, std::vector<Item*> items = {});

    Monster *monster;
    std::vector<Item*> items;

    bool operator==(AvatarWidget *otherAvatar);

private:

//    Hero *hero;
};

#endif // HEROAVATAR_H
