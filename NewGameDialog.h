#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include "common.h"

#define DIFFICULTY_FN( lvl) void setMode ## lvl () { setMode(Difficulty::lvl); }
#define CONNECT_DIFFICULTY(btn, lvl) connect(ui->btn, SIGNAL(clicked(bool)), this, SLOT(setMode ## lvl ()));

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();

private:
    Ui::NewGameDialog *ui;
    void setMode(Difficulty df);

private slots:
    DIFFICULTY_FN(Easy)
    DIFFICULTY_FN(Medium)
    DIFFICULTY_FN(Hard)
    DIFFICULTY_FN(Random)
    DIFFICULTY_FN(Perfect)

signals:
    void setDifficulty(Difficulty df);
};

#endif // NEWGAMEDIALOG_H
