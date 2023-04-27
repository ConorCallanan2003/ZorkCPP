#include "avatarwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

AvatarWidget::AvatarWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(this->parentWidget()->width()/2 - this->width()/2, this->parentWidget()->height()/2  - this->height()/2, 50, 50);
}

void AvatarWidget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // set anti-aliasing for smooth edges
    painter.setPen(Qt::black); // set the pen color to black
    painter.setBrush(Qt::red); // set the brush color to red
    painter.drawEllipse(rect()); // draw a circle that fits the widget's bounding rectangle

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(50, 50);

}

void AvatarWidget::setDiameter(int diameter)
{
    m_diameter = diameter;
    update();
}

void AvatarWidget::moveDirection(int x, int y) {

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");

    animation->setDuration(200);

    QPoint startPos = this->pos();

    QPoint endPos = QPoint(startPos.x(), startPos.y());

    // Below code is shit. Kind of works though. Must be changed.
    if((startPos.x() + x) < this->parentWidget()->width()-50) {
        if ((startPos.x() + x) > 0) {
            if ((startPos.y() + y) < this->parentWidget()->height()-40) {
                if ((startPos.y() + y) > 0) {
                    endPos = QPoint(startPos.x() + x, startPos.y() + y);
                } else {
                    endPos = QPoint(startPos.x() + x, 0);
                }
            } else {
                qDebug() << "HIT";
                endPos = QPoint(startPos.x() + x, this->parentWidget()->height()-40);
            }
        } else {
            endPos = QPoint(0, startPos.y() + y);
        }
    } else {
        endPos = QPoint(this->parentWidget()->width()-50, startPos.y() + y);
    }

    qDebug() << "XPos: " << endPos.x() << "YPos: " << endPos.y();
//    qDebug( "C Style Debug Message" );

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    this->xPos = endPos.x();
    this->yPos = endPos.y();

    animation->start();

}
