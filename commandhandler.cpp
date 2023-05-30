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
        if(target == currentLevel->monster->name) {
            hero->moveTo(currentLevel->monster->avatar->pos());
            return "You are now beside " + currentLevel->monster->name;
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

    if(command.substr(0, 4) == "kill") {
        std::string target = command.substr(5).c_str();
        if(target == currentLevel->monster->name) {
            if(hero->avatar->overlapping(currentLevel->monster->avatar)) {
                currentLevel->monster->avatar->path = "";
                hero->kill(currentLevel->monster);
//                w->wonDialog->raise();
//                w->wonDialog->show();
                Level::levelIndex++;
                if(Level::levelIndex < (Level::levels.size())) {
                    MainWindow *w2 = new MainWindow();
                    int index = Level::levelIndex;
                    Level *level = Level::levels[index];
                    w2->runGame(level);
//                    w->close();
                }
            }
        }
        return "You are not close enough to this item to take it";

    }

    return "Invalid command";

}
