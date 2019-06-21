#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "common.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool isIngame();

private:
    Ui::MainWindow *ui;
    bool ingame;
    Game game;

    Difficulty difficulty;

    bool wantToLoseEverything();

private slots:
    void setDifficulty(Difficulty dif);
    void newGame();
    void exitGame();
};

#endif // MAINWINDOW_H
