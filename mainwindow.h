#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include "ui_mainwindow.h"
#include "item.h"
#include "hero.h"
#include "dialog.h"
#include "mainwindow.h"
#include "level.h"
#include "commandhandler.h"
#include "avatarwidget.h"
#include "heroavatar.h"
#include "monster.h"
#include "LevelInfoStruct.h"
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <thread>
#include <QPropertyAnimation>
#include <QPalette>
#include <QSize>
#include <QKeyEvent>
#include <QPointF>
#include <QDebug>

class CommandHandler;

class Hero;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int runGame(Level *level);
    void start();

    void resetGame();

    Dialog* wonDialog;
    Dialog* deadDialog;
    Dialog* startDialog1;
    Dialog* startDialog2;
    Dialog* congratsDialog;

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:

    void on_actionText_Based_triggered();

    void on_actionGUI_Based_triggered();

    void westclicked();

    void southclicked();

    void northclicked();

    void eastclicked();

    void disable_buttons();

    void enable_buttons();

    void hide_ui_elements();
    void show_ui_elements();

    void hide_text_elements();
    void show_text_elements();

    void on_submitButton_clicked();

private:

    void onMoveButtonClicked();

    QPushButton *northButton;
    QPushButton *southButton;
    QPushButton *eastButton;
    QPushButton *westButton;

    Ui::MainWindow *ui;
    Hero *hero;
    std::vector<Item*> items;

    Level *currentLevel;

    int getScore(LevelInfo);

    CommandHandler *commandHandler;
};
#endif // MAINWINDOW_H
