#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include <QObject>

class Game;
class GameMap;

class Player : public QObject
{
    Q_OBJECT
public:
    Player();
    virtual ~Player();

    Player(PlayerIcon icon);
    PlayerIcon icon() const;
    bool isLocal() const;
    void setLocal(bool local);
    void setIcon(const PlayerIcon& icon);
    void appendToGame(Game *g);

    virtual void process();

    static Player *NoPlayer;

protected:
    PlayerIcon m_icon;
    bool m_local;
    Game *game;
    GameMap *map;
};

#endif // PLAYER_H
