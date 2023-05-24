#include "heroavatar.h"
#include <QPropertyAnimation>

HeroAvatar::HeroAvatar(QWidget *parent, QPointF *startPos, std::string path)
    : AvatarWidget(parent, startPos, path) {}

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
                qDebug() << "HIT";
                endPos = QPoint(startPos.x() + x, 649);
            }
        } else {
            endPos = QPoint(1, startPos.y());
        }
    } else {
        endPos = QPoint(649, startPos.y() + y);
    }

    qDebug() << "XPos: " << endPos.x() << "YPos: " << endPos.y();
    //    qDebug( "C Style Debug Message" );

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);


    this->xPos = endPos.x();
    this->yPos = endPos.y();

    animation->start();
}


bool HeroAvatar::overlapping(AvatarWidget avatar) {

    int hx = pos().x();
    int hy = pos().y();

    int ax = avatar.pos().x();
    int ay = avatar.pos().y();

    if((hx < (ax+50)) && (hx > (ax-50))) {
        if((hy < (ay+50)) && (hy > (ay-50))) {
            return true;
        }
    }

    return false;

}
