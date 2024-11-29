#ifndef _LINKBOOST_H_
#define _LINKBOOST_H_

#include "ability.h"
#include <iostream>

class Player;

class Linkboost: public Ability {
    public:
        Linkboost(Player* player);
        bool use(Link &targetLink) override;
        bool use(Cell &targetCell) override;
        std::string getName() const override;
};

#endif
