#ifndef AVATARWIDGET_H
#define AVATARWIDGET_H

#include <QWidget>
#include <string>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>
#include <QImage>


class AvatarWidget : public QWidget
{
public:
    AvatarWidget(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png");

    virtual ~AvatarWidget() {
        delete startPos;
    }

    int xPos;
    int yPos;

    std::string path;
    QPointF *startPos;

    void moveDirection(int x, int y);

//    bool operator+(AvatarWidget *otherAvatar);
    bool overlapping(AvatarWidget *avatar);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    int m_diameter;
};

#endif
