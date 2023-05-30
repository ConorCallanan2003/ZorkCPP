#ifndef MOVABLEAVATAR_H
#define MOVABLEAVATAR_H
#include <QPoint>


class MovableAvatar
{
public:
    MovableAvatar();

    virtual void moveDirection(int x, int y) = 0;
    virtual void moveTo(QPoint newPos) = 0;
};

#endif // MOVABLEAVATAR_H
