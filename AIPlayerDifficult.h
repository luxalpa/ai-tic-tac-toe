#ifndef AIPLAYERDIFFICULT_H
#define AIPLAYERDIFFICULT_H

#include "common.h"
#include "Player.h"

class GameMap;

class AIPlayerDifficult : public Player
{
public:
    AIPlayerDifficult(Difficulty dif);

    void process();

protected:
    int minimax(GameMap &map, int playerId, QPoint move, int depth);

private:
    float difLevel;
};

#endif // AIPLAYERDIFFICULT_H
