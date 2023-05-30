#include "item.h"
#include <string>
#include <vector>

Item::Item(std::string name, std::string imagePath) : Thing(name)
{
    this->imagePath = imagePath;
}

