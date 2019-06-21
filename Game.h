#ifndef GAME_H
#define GAME_H

#include "GameMap.h"
#include "Player.h"
#include "common.h"
#include <QList>
#include <QPoint>
#include <QObject>

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    Player* addHumanPlayer();
    Player* addAIPlayer(Difficulty mode);
    void removeAllPlayers();

    GameMap* map();
    void reset();

    Player* currentPlayer();
    PlayerIcon currentPlayerIcon();

    bool allowsInput();
    bool isRunning();

    QList<Player*> players() const;

public slots:
    bool activateField(QPoint pos);
    bool activateField(int x, int y);
    void start();
    void end();

signals:
    void winner(Player *p, QSet<QPoint> fields);

private:
    void nextTurn();
    bool checkWinner(int x, int y);

    const int winLength = 3;

    GameMap m_map;
    QList<Player*> m_players;
    int curPlayerId;

    bool active;
};

#endif // GAME_H
