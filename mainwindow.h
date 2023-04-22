#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include "avatarwidget.h"

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

private slots:
    void on_actionText_Based_triggered();

    void on_actionGUI_Based_triggered();

    void on_westButton_clicked();

    void on_southButton_clicked();

    void on_northButton_clicked();

    void on_eastButton_clicked();

    void disable_buttons();

    void enable_buttons();

private:
    Ui::MainWindow *ui;
    QDialog *dialog;
    AvatarWidget *avatarWidget;
};
#endif // MAINWINDOW_H
