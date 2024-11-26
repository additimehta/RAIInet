#ifndef _ABILITY_H_
#define _ABILITY_H_

#include <string>
#include "link.h"
#include "cell.h"

class Player;

class Ability {
    Player *player;
    bool isUsed;
    public:
        virtual void use(Link &targetLink) {}
        virtual void use(Cell &targetCell) {}
        virtual ~Ability() = 0;
};

#endif
