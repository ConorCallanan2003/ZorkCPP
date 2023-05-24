#include "level.h"
#include <QPixmap>

Level::Level(QWidget *parent, HeroAvatar *hero, AvatarWidget *monster, AvatarWidget *tool, std::string mapPath)
{

    this->parent = parent;
    this->hero = hero;
    this->monster = monster;
    this->tool = tool;
    this->mapPath = mapPath;

}

void Level::generateLevel() {

    QPixmap pixmap(mapPath.c_str());
    pixmap = pixmap.scaled(QSize(770, 770));
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->parent->setPalette(palette);

}
