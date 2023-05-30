#include "heroavatar.h"
#include "monster.h"
#include <QPropertyAnimation>

typedef int (*FuncPtr)(int);

HeroAvatar::HeroAvatar(QWidget *parent, QPointF *startPos, std::string path, Monster *monster, Hero *hero, std::vector<Item*> items, MainWindow *w)
    : AvatarWidget(parent, startPos, path), MovableAvatar() {
    this->monster = monster;
    this->hero = hero;
    this->items = items;
    this->w = w;
}

bool HeroAvatar::operator==(AvatarWidget *otherAvatar) {
    return overlapping(otherAvatar);
}

void HeroAvatar::moveDirection(int x, int y) {
    if(w->congratsDialog != nullptr) {
        w->congratsDialog->hide();
    }

    if(w->startDialog1 != nullptr && w->startDialog2 != nullptr) {
        w->startDialog1->hide();
        w->startDialog2->hide();
    }

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");

    animation->setDuration(200);

    QPoint startPos = this->pos();

    QPoint endPos = QPoint(startPos.x(), startPos.y());

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

    this->xPos = endPos.x();
    this->yPos = endPos.y();

    if(this->monster->avatar->path != "") {
        if(*this==(this->monster->avatar)) {
            bool killed = hero->kill(this->monster);
            if(killed) {
                if(w->deadDialog != nullptr) {
                    w->deadDialog->hide();
                }
                w->wonDialog->raise();
                w->wonDialog->show();
                extern int levelIndex;
                levelIndex++;
                if(levelIndex < (Level::levels.size())) {
                    w->close();
                    MainWindow *w2 = new MainWindow();
                    int index = levelIndex;
                    Level *level = Level::levels[index];
                    w2->runGame(level);
                }
            } else {
                this->hide();
                w->deadDialog->raise();
                w->deadDialog->show();
            }
        }
    }

    //    if(inventory == nullptr) {
    for (Item* item : this->items) {
        if(item->avatar->path != ""){
            if(*this==item->avatar) {
                hero->take(item);
            }
        }
    }
//        }
    animation->start();
}


void HeroAvatar::moveTo(QPoint newPos) {

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");

    animation->setDuration(200);

    QPoint startPos = this->pos();

    QPoint endPos = newPos;

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    this->xPos = endPos.x();
    this->yPos = endPos.y();

    animation->start();

}
