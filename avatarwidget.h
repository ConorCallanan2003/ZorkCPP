#ifndef AVATARWIDGET_H
#define AVATARWIDGET_H

#include <QWidget>

class AvatarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AvatarWidget(QWidget *parent = nullptr);

    int xPos;
    int yPos;

    void setDiameter(int diameter);

    void moveDirection(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_diameter;
};


#endif
