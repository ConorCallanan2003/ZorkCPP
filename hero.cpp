#include "hero.h"
#include <QPropertyAnimation>
#include <chrono>
#include <thread>

Hero::Hero(Dialog *deadDialog, Dialog *wonDialog, MainWindow *w)
{
    this->deadDialog = deadDialog;
    this->wonDialog = wonDialog;
    this->w = w;
}


bool Hero::kill(Monster *monster) {
    if(this->inventory == monster->weakness) {
        return true;
    }
    return false;
}

void Hero::take(Item *item) {
//    item->avatar->deleteLater();
//    item->avatar->path = "";
    delete(item->avatar);
    this->inventory = item;
}

void Hero::moveDirection(int x, int y) {

    if(w->congratsDialog != nullptr) {
        w->congratsDialog->hide();
    }

    if(w->startDialog1 != nullptr && w->startDialog2 != nullptr) {
        w->startDialog1->hide();
        w->startDialog2->hide();
    }

    QPropertyAnimation *animation = new QPropertyAnimation(this->avatar, "pos");

    animation->setDuration(200);

    QPoint startPos = this->avatar->pos();

    QPoint endPos = QPoint(startPos.x(), startPos.y());

    // Below code is shit. Kind of works though. Must be changed.
    if((startPos.x() + x) < 650) {
        if ((startPos.x() + x) > 0) {
            if ((startPos.y() + y) < 650) {
                if ((startPos.y() + y) > 25) {
                    endPos = QPoint(startPos.x() + x, startPos.y() + y);
                } else {
                    endPos = QPoint(startPos.x() + x, 26);
                }
            } else {
                endPos = QPoint(startPos.x() + x, 649);
            }
        } else {
            endPos = QPoint(1, startPos.y());
        }
    } else {
        endPos = QPoint(649, startPos.y() + y);
    }

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    avatar->xPos = endPos.x();
    avatar->yPos = endPos.y();

    if(this->avatar->monster->avatar->path != "") {
        if(*avatar==(this->avatar->monster->avatar)) {
            bool killed = kill(this->avatar->monster);
            if(killed) {
                if(deadDialog != nullptr) {
                    deadDialog->hide();
                }
                wonDialog->raise();
                wonDialog->show();
                Level::levelIndex++;
                if(Level::levelIndex < (Level::levels.size())) {
                    w->close();
                    MainWindow *w2 = new MainWindow();
                    int index = Level::levelIndex;
                    Level *level = Level::levels[index];
                    w2->runGame(level);
                }
            } else {
                this->avatar->hide();
                deadDialog->raise();
                deadDialog->show();
            }
        }
    }

//    if(inventory == nullptr) {
        for (Item* item : this->avatar->items) {
            if(item->avatar->path != ""){
                if(*avatar==item->avatar) {
                    take(item);
                }
            }
        }
//    }
    animation->start();
}


void Hero::moveTo(QPoint newPos) {

    QPropertyAnimation *animation = new QPropertyAnimation(this->avatar, "pos");

    animation->setDuration(200);

    QPoint startPos = this->avatar->pos();

    QPoint endPos = newPos;

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    avatar->xPos = endPos.x();
    avatar->yPos = endPos.y();

    animation->start();

}
