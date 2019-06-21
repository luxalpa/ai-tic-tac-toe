/********************************************************************************
** Form generated from reading UI file 'NewGameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDIALOG_H
#define UI_NEWGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnEasy;
    QPushButton *btnMedium;
    QPushButton *btnHard;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *btnRandom;
    QPushButton *btnPerfect;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *lblSelectDifficulty;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName(QStringLiteral("NewGameDialog"));
        NewGameDialog->setWindowModality(Qt::ApplicationModal);
        NewGameDialog->resize(300, 260);
        NewGameDialog->setModal(true);
        gridLayout_2 = new QGridLayout(NewGameDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(NewGameDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnEasy = new QPushButton(groupBox);
        btnEasy->setObjectName(QStringLiteral("btnEasy"));

        gridLayout->addWidget(btnEasy, 0, 0, 1, 1);

        btnMedium = new QPushButton(groupBox);
        btnMedium->setObjectName(QStringLiteral("btnMedium"));

        gridLayout->addWidget(btnMedium, 0, 1, 1, 1);

        btnHard = new QPushButton(groupBox);
        btnHard->setObjectName(QStringLiteral("btnHard"));

        gridLayout->addWidget(btnHard, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);

        groupBox_2 = new QGroupBox(NewGameDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnRandom = new QPushButton(groupBox_2);
        btnRandom->setObjectName(QStringLiteral("btnRandom"));

        gridLayout_3->addWidget(btnRandom, 0, 0, 1, 1);

        btnPerfect = new QPushButton(groupBox_2);
        btnPerfect->setObjectName(QStringLiteral("btnPerfect"));

        gridLayout_3->addWidget(btnPerfect, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(119, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        lblSelectDifficulty = new QLabel(NewGameDialog);
        lblSelectDifficulty->setObjectName(QStringLiteral("lblSelectDifficulty"));
        lblSelectDifficulty->setMinimumSize(QSize(0, 100));
        lblSelectDifficulty->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblSelectDifficulty, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(99999, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(NewGameDialog);

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QApplication::translate("NewGameDialog", "Select Difficulty", 0));
        groupBox->setTitle(QApplication::translate("NewGameDialog", "Ordinary Modes", 0));
        btnEasy->setText(QApplication::translate("NewGameDialog", "Easy", 0));
        btnMedium->setText(QApplication::translate("NewGameDialog", "Medium", 0));
        btnHard->setText(QApplication::translate("NewGameDialog", "Hard", 0));
        groupBox_2->setTitle(QApplication::translate("NewGameDialog", "Other Modes", 0));
        btnRandom->setText(QApplication::translate("NewGameDialog", "Random", 0));
        btnPerfect->setText(QApplication::translate("NewGameDialog", "Perfect", 0));
        lblSelectDifficulty->setText(QApplication::translate("NewGameDialog", "Select difficulty", 0));
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDIALOG_H
