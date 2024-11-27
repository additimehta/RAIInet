#ifndef _ABILITY_H_
#define _ABILITY_H_

#include <string>
#include "link.h"
#include "cell.h"

class Player;

class Ability {
    protected:
    Player *player;
    bool isUsed;
    public:
        Ability(Player *player);
        virtual void use(Link &targetLink) {}
        virtual void use(Cell &targetCell) {}
        bool hasBeenUsed() const;
        void markUsed();
        virtual ~Ability() = 0;
};

#endif
