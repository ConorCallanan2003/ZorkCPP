#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "mainwindow.h"
#include "level.h"
#include "hero.h"

class Hero;

class MainWindow;

class CommandHandler
{
public:
    CommandHandler(MainWindow *w);

    MainWindow *w;

    std::string handleCommand(std::string command, Level *currentLevel, Hero *hero);

};

#endif // COMMANDHANDLER_H
