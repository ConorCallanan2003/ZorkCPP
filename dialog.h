#ifndef DIALOG_H
#define DIALOG_H
#include "avatarwidget.h"
#include <QWidget>

class Dialog : public AvatarWidget
{
public:
    Dialog(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png");

    void paintEvent(QPaintEvent *event);
};

#endif // DIALOG_H
