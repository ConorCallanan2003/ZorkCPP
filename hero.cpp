#include "hero.h"
#include "LevelInfoStruct.h"
#include <QPropertyAnimation>
#include <chrono>
#include <thread>

Hero::Hero(Dialog *deadDialog, Dialog *wonDialog, MainWindow *w) : Living()
{
    this->deadDialog = deadDialog;
    this->wonDialog = wonDialog;
    this->w = w;
}


bool Hero::kill(Monster *monster) {
    if(this->inventory == monster->weakness) {
        monster->alive = false;
        extern LevelInfo levelInfo;
        levelInfo.score += 10;
        levelInfo.round += 1;
        qDebug() << levelInfo.round;
        qDebug() << levelInfo.score;
        return true;
    }
    return false;
}

void Hero::take(Item *item) {
    extern LevelInfo levelInfo;
    levelInfo.score += 10;
    delete(item->avatar);
    this->inventory = item;
}


