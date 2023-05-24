#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "avatarwidget.h"

class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", AvatarWidget *monster = nullptr, AvatarWidget *item1 = nullptr);

    void moveDirection(int x, int y);

    bool overlapping(AvatarWidget *avatar);
private:
    AvatarWidget *monster;
    AvatarWidget *item1;
};

#endif // HEROAVATAR_H
