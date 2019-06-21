#ifndef AIPLAYERRANDOM_H
#define AIPLAYERRANDOM_H

#include "Player.h"

class AIPlayerRandom : public Player
{
public:
    AIPlayerRandom();
    ~AIPlayerRandom();

    // Player interface
public:
    void process();
};

#endif // AIPLAYERRANDOM_H
