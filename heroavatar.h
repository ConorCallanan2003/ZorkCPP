#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "item.h"
#include "monster.h"
//#include "hero.h"


class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", Monster *monster = nullptr, std::vector<Item*> items = {});

//    void moveDirection(int x, int y);
    bool overlapping(AvatarWidget *avatar);

    // Move both of these from public and make friend of Hero
//    bool (*killptr)(Monster*);
    Monster *monster;
    std::vector<Item*> items;
private:

//    Hero *hero;
};

#endif // HEROAVATAR_H
