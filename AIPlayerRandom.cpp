#include "AIPlayerRandom.h"
#include <QDebug>
#include <QList>
#include "Game.h"
#include "GameMap.h"

AIPlayerRandom::AIPlayerRandom()
{

}

AIPlayerRandom::~AIPlayerRandom()
{

}



void AIPlayerRandom::process()
{
    QList<QPoint> freeFields;

    for(int x = 0; x < map->width(); x++) {
        for(int y = 0; y < map->height(); y++) {
            if(map->playerAt(x, y) == Player::NoPlayer)
                freeFields.append(QPoint(x, y));
        }
    }

    int fieldIndex = qrand() % freeFields.size();
    if(!game->activateField(freeFields[fieldIndex])) {
        qDebug() << "Error :(";
    }
}
