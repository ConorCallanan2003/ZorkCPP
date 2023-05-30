#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include "avatarwidget.h"
#include "thing.h"

struct ItemDetails {
    unsigned int value : 10;
};

class Item : public Thing
{
public:
    Item(std::string name, std::string imagePath);

    AvatarWidget *avatar;

    ItemDetails itemDetails;

    std::string imagePath;

    void generateLevel();
};

#endif // ITEM_H
