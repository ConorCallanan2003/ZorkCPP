#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include "avatarwidget.h"

class Item
{
public:
    Item(std::string name, int value, std::vector<std::string> abilities, AvatarWidget *avatar);

    AvatarWidget *avatar;

    std::string description();

    std::vector<std::string> abilities;
    std::string name;
    int value;

    void generateLevel();
};

#endif // ITEM_H
