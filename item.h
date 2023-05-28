#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include "avatarwidget.h"

class Item
{
public:
    Item(std::string name);

    AvatarWidget *avatar;

    std::string description();

    std::string name;

    void generateLevel();
};

#endif // ITEM_H
