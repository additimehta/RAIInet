#ifndef _LINKBOOST_H_
#define _LINKBOOST_H_

#include "ability.h"
#include <iostream>

class Linkboost: public Ability {
    public:
        Linkboost(Player* player);
        bool use(Link &targetLink) override;
        std::string getName() const override;
};

#endif
