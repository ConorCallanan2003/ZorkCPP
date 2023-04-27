#include "avatarwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

AvatarWidget::AvatarWidget(QWidget *parent) : QWidget(parent)
{

}

void AvatarWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::red);
    painter.drawEllipse(rect().center(), m_diameter, m_diameter);
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

    if(((startPos.x() + x) < 600) && ((startPos.x() + x) > 0) && ((startPos.y() + y) < 600) && ((startPos.y() + y) > 0)) {
        endPos = QPoint(startPos.x() + x, startPos.y() + y);
    }

    qDebug() << "XPos: " << endPos.x() << "YPos: " << endPos.y();
//    qDebug( "C Style Debug Message" );

    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    this->xPos = endPos.x();
    this->yPos = endPos.y();

    animation->start();

}
