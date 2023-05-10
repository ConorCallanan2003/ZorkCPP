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

    QSizeF newSize = QSizeF(500, 500) * 0.25;
    QPointF newPos = QPointF(0,0);

    painter.drawImage(QRectF(newPos, newSize), image);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(200, 200);

}


//void AvatarWidget::moveDirection(int x, int y) {



//}
