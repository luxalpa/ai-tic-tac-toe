#include "NewGameDialog.h"
#include "ui_NewGameDialog.h"
#include <QDebug>

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
    setWindowFlags((windowFlags() | Qt::MSWindowsFixedSizeDialogHint) & ~Qt::WindowContextHelpButtonHint);
    CONNECT_DIFFICULTY(btnEasy, Easy);
    CONNECT_DIFFICULTY(btnMedium, Medium);
    CONNECT_DIFFICULTY(btnHard, Hard);
    CONNECT_DIFFICULTY(btnRandom, Random);
    CONNECT_DIFFICULTY(btnPerfect, Perfect);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::setMode(Difficulty df)
{
    emit setDifficulty(df);
    accept();
}
