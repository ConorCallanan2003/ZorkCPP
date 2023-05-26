#include "item.h"
#include <string>
#include <vector>

Item::Item(std::string name, int value, std::vector<std::string> abilities, AvatarWidget *avatar)
{
    this->name = name;
    this->value = value;
    this->abilities = abilities;
    this->avatar = avatar;
}

//std::string Item::description() {

//    std::string response = "This is a " + this->name + ". It has a value of " + value + " gold. It's abilities are as follows: ";

//    std::string response = "test";

//    for(int i = 0; i < this->abilities.size(); i++) {
//        response += "\n";
//        response += abilities[i];
//    }

//}
