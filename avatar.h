#ifndef AVATAR_H
#define AVATAR_H

class Avatar{
public:
    Avatar(int diameter);

    ~Avatar();

    void move(int x, int y) {
        this->x_pos += x;
        this->y_pos += y;
    }

    int x_pos;
    int y_pos;
    int diameter;
};

#endif // AVATAR_H
