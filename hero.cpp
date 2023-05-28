#include "hero.h"
#include <QPropertyAnimation>

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
    this->inventory = item;
}

void Hero::moveDirection(int x, int y) {

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

    this->avatar->xPos = endPos.x();
    this->avatar->yPos = endPos.y();

    if(this->avatar->monster->avatar->path != "") {
        if(this->avatar->overlapping(this->avatar->monster->avatar)) {
            bool killed = kill(this->avatar->monster);
            if(killed) {
                this->avatar->monster->avatar->deleteLater();
                this->avatar->monster->avatar->path = "";
                wonDialog->raise();
                wonDialog->show();

                w->runGame(":/images/desert.png", ":/images/gremlin.png", ":/images/sword.png", new Item("Sword"));
            } else {
//                this->avatar->deleteLater();
//                this->avatar->path = "";
                this->avatar->hide();
                deadDialog->raise();
                deadDialog->show();
            }
        }
    }

    if(this->avatar->item1->avatar->path != ""){
        if(this->avatar->overlapping(this->avatar->item1->avatar)) {
            this->avatar->item1->avatar->deleteLater();
            this->avatar->item1->avatar->path = "";
            take(this->avatar->item1);
        }
    }

    animation->start();
}
