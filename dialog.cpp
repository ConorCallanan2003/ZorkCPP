#include "dialog.h"

Dialog::Dialog(QWidget *parent, QPointF *startPos, std::string path) : AvatarWidget(parent, startPos, path)
{

}


void Dialog::paintEvent(QPaintEvent *event) {
    QImage image(this->path.c_str());

    QPainter painter(this);

    QSizeF newSize = QSizeF(1500, 1500) * 0.25;
//    QPointF newPos = QPointF(0,0);

    painter.drawImage(QRectF(*startPos, newSize), image);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(1000, 1000);
}
