#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QDebug>
#include "NewGameDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionStartNewGame, SIGNAL(triggered(bool)), this, SLOT(newGame()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exitGame()));

    ingame = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isIngame()
{
    return game.isRunning();
}

bool MainWindow::wantToLoseEverything()
{
    if(isIngame()) {
        if(QMessageBox::No == QMessageBox::warning(this, "Warning", "Game progress will be lost. Are you sure?", QMessageBox::Yes | QMessageBox::No)) {
            return false;
        }
    }
    return true;
}

void MainWindow::setDifficulty(Difficulty dif)
{
    difficulty = dif;
}


void MainWindow::newGame()
{
    if(!wantToLoseEverything())
        return;

    // New Game Dialog

    NewGameDialog dialog;
    connect(&dialog, SIGNAL(setDifficulty(Difficulty)), this, SLOT(setDifficulty(Difficulty)));
    if(dialog.exec() == 0) {
        // cancel
        return;
    }

    ingame = true;
    game.removeAllPlayers();
    game.addHumanPlayer();
    game.addAIPlayer(difficulty);
    game.start();
    ui->gameWidget->appendToGame(&game);
}

void MainWindow::exitGame()
{
    if(!wantToLoseEverything())
        return;
    exit(0);
}
