#ifndef HEROAVATAR_H
#define HEROAVATAR_H
#include "item.h"
#include "monster.h"
#include "movableavatar.h"
#include "mainwindow.h"

class Hero;
class MainWindow;

class HeroAvatar : public AvatarWidget, public MovableAvatar
{
public:
    HeroAvatar(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png", Monster *monster = nullptr, Hero *hero = nullptr, std::vector<Item*> items = {}, MainWindow *w = nullptr);
    bool operator==(AvatarWidget *otherAvatar);
    void moveDirection(int x, int y);
    void moveTo(QPoint newPos);

private:
    Monster *monster;
    Hero *hero;
    std::vector<Item*> items;
    MainWindow *w;
//    friend class Hero;
//    friend class MainWindow;
//    friend class CommandHandler;
};

#endif // HEROAVATAR_H
