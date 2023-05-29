#include "commandhandler.h"

CommandHandler::CommandHandler(MainWindow *w)
{
    this->w = w;
}


std::string CommandHandler::handleCommand(std::string command, Level *currentLevel, Hero *hero) {

    if(command.substr(0, 4) == "goto") {
        std::string target = command.substr(5).c_str();

        for(Item *item : currentLevel->items) {
            if(target == item->name) {
                hero->moveTo(item->avatar->pos());
                return "You are now beside " + item->name;
            }
        }

        return "Item does not exist";

    }

    if(command.substr(0, 4) == "take") {
        std::string target = command.substr(5).c_str();

        for(Item *item : currentLevel->items) {
            if(target == item->name) {
                if(hero->avatar->overlapping(item->avatar)) {
                    item->avatar->path = "";
                    hero->take(item);
                    return item->name + " is now in your inventory";
                }
            }
        }
        return "You are not close enough to this item to take it";

    }

    return "Invalid command";

}
