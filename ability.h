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
        virtual bool use(Link &targetLink); // return true if successful and false otherwise
        virtual bool use(Cell &targetCell); // return true if successful and false otherwise
        bool hasBeenUsed() const;
        void markUsed();
        virtual ~Ability() = 0;
        virtual std::string getName() const = 0;
};

#endif
