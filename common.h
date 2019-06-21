#ifndef COMMON
#define COMMON

#include <QPoint>
#include <qhash.h>

enum class Difficulty {
    Easy,
    Medium,
    Hard,
    Random,
    Perfect
};

enum class PlayerIcon { // temporary
    None,
    Circle,
    Cross
};

inline uint qHash (const QPoint & key)
{
    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
}

inline int randInt(int min, int max) {
    return qrand()%(max-min + 1) + min;
}

#endif // COMMON

