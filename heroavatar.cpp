#include "heroavatar.h"
#include <QPropertyAnimation>

typedef int (*FuncPtr)(int);

HeroAvatar::HeroAvatar(QWidget *parent, QPointF *startPos, std::string path, Monster *monster, Item *item1/*, Hero *hero*/)
    : AvatarWidget(parent, startPos, path) {
    this->monster = monster;
    this->item1 = item1;
//    this->hero = hero;
}

void HeroAvatar::moveDirection(int x, int y) {

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");

    animation->setDuration(200);

    QPoint startPos = this->pos();

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

//    qDebug() << "XPos: " << endPos.x() << "YPos: " << endPos.y();
    //    qDebug( "C Style Debug Message" );

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    this->xPos = endPos.x();
    this->yPos = endPos.y();

    if(monster->avatar->path != "") {
        if(overlapping(monster->avatar)) {
            monster->avatar->deleteLater();
            monster->avatar->path = "";
//            bool survived = hero->kill(monster);
//            if(survived) {
//                qDebug() << "Survived";
//            } else {
//                qDebug() << "Died";
//            }
        }
    }

    if(item1->avatar->path != "")
    if(overlapping(item1->avatar)) {
        item1->avatar->deleteLater();
        item1->avatar->path = "";
//        hero->take(item1);
    }

    animation->start();
}

bool HeroAvatar::overlapping(AvatarWidget *avatar) {

    int hx = pos().x() + (width()/2);
    int hy = pos().y() + (height()/2);

    int ax = avatar->pos().x() + (avatar->width()/2);
    int ay = avatar->pos().y() + (avatar->height()/2);

    if (hx < (ax+150) && hx > (ax-150)) {
        if (hy < (ay+150) && hy > (ay-150)) {
            return true;
        }
    }
    return false;

}
