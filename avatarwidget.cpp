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
//    painter.setRenderHint(QPainter::Antialiasing); // set anti-aliasing for smooth edges
//    painter.setPen(Qt::black); // set the pen color to black
//    painter.setBrush(Qt::red); // set the brush color to red
//    painter.drawEllipse(rect()); // draw a circle that fits the widget's bounding rectangle

    QSizeF newSize = QSizeF(image.size()) * 0.1;
    QPointF newPos = QPointF(0,0);

    painter.drawImage(QRectF(newPos, newSize), image);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(200, 200);

}


void AvatarWidget::moveDirection(int x, int y) {

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
