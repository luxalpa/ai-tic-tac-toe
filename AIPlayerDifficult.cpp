#include "AIPlayerDifficult.h"
#include <QDebug>
#include "Game.h"
#include "GameMap.h"

AIPlayerDifficult::AIPlayerDifficult(Difficulty dif)
{
    switch(dif) {
    case Difficulty::Easy:
        difLevel = 1.0;
        break;
    case Difficulty::Medium:
        difLevel = 0.55;
        break;
    case Difficulty::Hard:
        difLevel = 0.5;
        break;
    case Difficulty::Perfect:
        difLevel = 0;
        break;
    }
}

void AIPlayerDifficult::process()
{
    int score = -1000;
    QPoint move(0,0);

    int playerId;

    for(playerId = 0; playerId < game->players().size(); playerId++) {
        if(game->players()[playerId] == this)
            break;
    }

    int curPlayerId = playerId;

    GameMap testMap = *map;

    for(int x = 0; x < map->width(); x++) {
        for(int y = 0; y < map->height(); y++) {
            if(map->playerAt(x, y) == Player::NoPlayer) {
                testMap.setField(x, y, this);
                int nextPlayerId = (curPlayerId+1) % game->players().size();
                int newScore = minimax(testMap, nextPlayerId, QPoint(x, y), 0);
                testMap.setField(x, y, Player::NoPlayer);
                if(newScore > score) {
                    move = QPoint(x, y);
                    score = newScore;
                }
            }
        }
    }

    if(!game->activateField(move))
        qDebug() << "Error! Panic!";
}

int AIPlayerDifficult::minimax(GameMap &map, int playerId, QPoint move, int depth)
{
    depth += 1;

    Player *winner = map.checkWinner(move.x(), move.y());

    int score;

    if(winner == this) {  // 100 - 0.5 * 100 * 2
        score = randInt((100 - depth) - difLevel * (100 - depth) * 2, (100 - depth) - difLevel * (100 - depth));
    } else if(winner == Player::NoPlayer) {
        score = 0;
    } else {
        score = randInt((-100 + depth) - difLevel * (-100 + depth), (-100 + depth) - difLevel * (-100 + depth) * 2);
    }

    if(winner != Player::NoPlayer || map.isFull()) { // if game is over
        return score;
    }

    Player *curPlayer = game->players()[playerId];

    score = curPlayer == this ? -10000 : 10000;

    for(int x = 0; x < map.width(); x++) {
        for(int y = 0; y < map.height(); y++) {
            if(map.playerAt(x, y) == Player::NoPlayer) {
                map.setField(x, y, curPlayer);
                int nextPlayerId = (playerId+1) % game->players().size();
                int newScore = minimax(map, nextPlayerId, QPoint(x, y), depth);
                map.setField(x, y, Player::NoPlayer);
                if((newScore > score && curPlayer == this) || (newScore < score && curPlayer != this)) {
                    move = QPoint(x, y);
                    score = newScore;
                }
            }
        }
    }

    return score;
}

