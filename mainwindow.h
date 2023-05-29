#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include "heroavatar.h"
#include "avatarwidget.h"
#include "monster.h"
#include "item.h"
#include "hero.h"
#include "dialog.h"
#include "mainwindow.h"
#include "level.h"

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

    void onMoveButtonClicked();

    QPushButton *northButton;
    QPushButton *southButton;
    QPushButton *eastButton;
    QPushButton *westButton;

    int runGame(Level *level);
    void start();

    void resetGame();

//    void game2();

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

//    void *nextGame(MainWindow *w);

private:
    Ui::MainWindow *ui;
    QDialog *dialog;
//    HeroAvatar *heroAvatar;
    Hero *hero;
//    AvatarWidget *monster;
    Monster *monster;
//    AvatarWidget *item1;
    Item *item1;
    Item *item2;
    Item *item3;
};
#endif // MAINWINDOW_H
