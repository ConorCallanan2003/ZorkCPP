#ifndef AVATARWIDGET_H
#define AVATARWIDGET_H

#include <QWidget>
#include <string>


class AvatarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AvatarWidget(QWidget *parent = nullptr, QPointF *startPos = new QPointF(0, 0), std::string path = ":images/hero.png");

    int xPos;
    int yPos;

    std::string path;
    QPointF *startPos;

    void moveDirection(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_diameter;
};


#endif
