#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "avatarwidget.h"

class HeroAvatar : public AvatarWidget
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png");

    void moveDirection(int x, int y);

    bool overlapping(AvatarWidget avatar);
};

#endif // HEROAVATAR_H
