#include "avatarwidget.h"

AvatarWidget::AvatarWidget(QWidget *parent, QPointF *startPos, std::string path) : QWidget(parent)
{
    this->startPos = startPos;
    this->path = path;
    int width = 200;
    setGeometry(startPos->x(), startPos->y(), width, width);
}

void AvatarWidget::paintEvent(QPaintEvent *)
{
    QImage image(this->path.c_str());

    QPainter painter(this);

    QSizeF newSize = QSizeF(500, 500) * 0.25;
    QPointF newPos = QPointF(0,0);

    painter.drawImage(QRectF(newPos, newSize), image);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(200, 200);
}

bool AvatarWidget::overlapping(AvatarWidget *avatar){
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

