#ifndef THING_H
#define THING_H
#include <string>

//struct ThingDetails {
//    unsigned int value : 8;
//    char level : 8;
//};

class Thing
{
public:
    Thing(std::string name/*, int value, char level*/);
    std::string name;
//    ThingDetails details;
};

#endif // THING_H
