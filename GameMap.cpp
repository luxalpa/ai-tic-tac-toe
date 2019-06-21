#include "GameMap.h"

#include "Player.h"

GameMap::GameMap()
{

}

GameMap::GameMap(int height, int width)
{
    m_width = width;
    m_height = height;
    init();
}

PlayerIcon GameMap::iconAt(int x, int y) const
{
    return playerAt(x, y)->icon();
}

Player* GameMap::playerAt(int x, int y) const
{
    if(x >= m_width || x < 0 || y >= m_height || y < 0)
        return Player::NoPlayer;
    return fields[x + m_width * y];
}

Player*GameMap::playerAt(QPoint p) const
{
    return playerAt(p.x(), p.y());
}

void GameMap::reset()
{
    init();
}

void GameMap::setField(int x, int y, Player* p)
{
    fields[x + m_width * y] = p;
}

bool GameMap::isFull() const
{
    for(int i = 0; i < fields.size(); i++) {
        if(fields[i] == Player::NoPlayer)
            return false;
    }
    return true;
}

void GameMap::init()
{
    fields.resize(m_height * m_width);
    for(int i = 0; i < fields.size(); i++) {
        fields[i] = Player::NoPlayer;
    }
}

int GameMap::width() const
{
    return m_width;
}

Player* GameMap::checkWinner(int x, int y)
{
    const int numWinConditions = 4;

    Player* winner = Player::NoPlayer;
    Player* players[numWinConditions];

    players[0] = getWinnerFromLine(QPoint(x, y), QPoint(1, 0), 3);
    players[1] = getWinnerFromLine(QPoint(x, y), QPoint(0, 1), 3);
    players[2] = getWinnerFromLine(QPoint(x, y), QPoint(1, 1), 3);
    players[3] = getWinnerFromLine(QPoint(x, y), QPoint(1, -1), 3);

    for(int i = 0; i < numWinConditions; i++) {
        if(players[i] != Player::NoPlayer) {
            winner = players[i];
            break;
        }
    }

    return winner;
}

Player* GameMap::getWinnerFromLine(QPoint pos, QPoint asc, int winLength, QSet<QPoint>* winningFields)
{
    Player *winner = Player::NoPlayer;

    for(int a = 0; a < winLength + 1; a++) {
        Player *owner = playerAt(pos.x() + (a - (winLength - 1)) * asc.x(),
                                        pos.y() + (a - (winLength - 1)) * asc.y());
        if(owner == Player::NoPlayer)
            continue;
        bool isWon = true;
        for(int i = 0; i < winLength; i++) {
            if(playerAt(pos.x() + (a - (winLength - 1) + i) * asc.x(),
                               pos.y() + (a - (winLength - 1) + i) * asc.y()
                               ) != owner) {
                isWon = false;
                break;
            }
        }
        if(isWon) {
            winner = owner;
            if(winningFields != NULL) {
                for(int i = 0; i < winLength; i++) {
                    winningFields->insert(QPoint(pos.x() + (a - (winLength - 1) + i) * asc.x(),
                                                pos.y() + (a - (winLength - 1) + i) * asc.y()));
                }
            }
        }
    }

    return winner;
}

int GameMap::height() const
{
    return m_height;
}

