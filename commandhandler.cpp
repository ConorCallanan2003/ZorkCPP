#include "commandhandler.h"

CommandHandler::CommandHandler(MainWindow *w)
{
    this->w = w;
}

struct CommandStruct {
    std::string commandWord;
};

std::string CommandHandler::handleCommand(std::string command, Level *currentLevel, Hero *hero) {

    CommandStruct cs;
    cs.commandWord = command.substr(0, 4).c_str();

    if(cs.commandWord == "goto") {
        std::string target = command.substr(5).c_str();
        for(Item *item : currentLevel->items) {
            if(item != nullptr && target == item->name) {
                if(item->avatar->pos().y() > 250) {
                    QPoint newLoc = QPoint(item->avatar->pos().x(), item->avatar->pos().y()-150);
                    hero->avatar->moveTo(newLoc);
                } else {
                    QPoint newLoc = QPoint(item->avatar->pos().x(), item->avatar->pos().y()+150);
                    hero->avatar->moveTo(newLoc);
                }
                return "<h2>You are now beside the " + item->name + "</h2>";
            }
        }
        if(target == currentLevel->monster->name) {
            hero->avatar->moveTo(currentLevel->monster->avatar->pos());
            return "<h2>You are now beside the " + currentLevel->monster->name + "</h2>";
        }
        return "<h2>Item does not exist</h2>";
    }

    if(cs.commandWord == "take") {
        std::string target = command.substr(5).c_str();

        for(Item *item : currentLevel->items) {
            if(item != nullptr && target == item->name) {
                if(hero->avatar==(item->avatar)) {
                    item->avatar->path = "";
                    hero->take(item);

                }
                return "<h2>" + item->name + " is now in your inventory</h2>";
            }
        }
        return "<h2>You are not close enough to this item to take it</h2>";

    }

    if(cs.commandWord == "kill") {
        std::string target = command.substr(5).c_str();
        if(currentLevel->monster != nullptr && target == currentLevel->monster->name) {
            if(hero->avatar==(currentLevel->monster->avatar)) {
                extern int levelIndex;
                currentLevel->monster->avatar->path = "";
                hero->kill(currentLevel->monster);
                levelIndex++;
                if(levelIndex < (Level::levels.size())) {
                    MainWindow *w2 = new MainWindow();
                    int index = levelIndex;
                    Level *level = Level::levels[index];
                    w2->runGame(level);
                    return "survived";
                }
            }
        }
        return "<h1>You DIED!</h1>";

    }

    return "<h1>INVALID COMMAND</h1>";

}
