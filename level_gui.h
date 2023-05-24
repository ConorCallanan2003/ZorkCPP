#ifndef LEVEL_H
#define LEVEL_H
#include "heroavatar.h"
#include "avatarwidget.h"
#include <QWidget>

class Level
{
public:

    Level(QWidget *parent, HeroAvatar *hero, AvatarWidget *monster, AvatarWidget *tool, std::string mapPath);

    QWidget *parent;
    HeroAvatar *hero;
    AvatarWidget *monster;
    AvatarWidget *tool;
    std::string mapPath;

    void generateLevel();

};

#endif // LEVEL_H
