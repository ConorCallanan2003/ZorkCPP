#include "avatarwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>
#include <QImage>

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

