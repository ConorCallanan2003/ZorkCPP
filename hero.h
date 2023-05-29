#ifndef HERO_H
#define HERO_H
#include "item.h"
#include "monster.h"
#include "heroavatar.h"
#include "dialog.h"
#include "mainwindow.h"

class MainWindow;

class Hero
{
public:
    Hero(Dialog *deadDialog, Dialog *wonDialog, MainWindow *w);

    HeroAvatar *avatar;

    Item *inventory;

    bool kill(Monster *monster);
    void take(Item *item);
    void moveDirection(int x, int y);
    void moveTo(QPoint pos);

    Dialog *deadDialog;
    Dialog *wonDialog;
    MainWindow *w;
};

#endif // HERO_H
