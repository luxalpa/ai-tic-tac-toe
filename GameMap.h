#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "common.h"
#include <QVector>
#include <QPoint>
#include <QSet>

class Player;

class GameMap
{
public:
    GameMap();
    GameMap(int height, int width);
    PlayerIcon iconAt(int x, int y) const;
    Player* playerAt(int x, int y) const;
    Player* playerAt(QPoint p) const;
    void reset();
    void setField(int x, int y, Player* p);
    bool isFull() const;

    int height() const;
    int width() const;
    Player* checkWinner(int x, int y);
    Player *getWinnerFromLine(QPoint pos, QPoint asc, int winLength, QSet<QPoint> *winningFields = NULL);

private:
    void init();

    int m_height;
    int m_width;
    QVector<Player*> fields;
};

#endif // GAMEMAP_H
