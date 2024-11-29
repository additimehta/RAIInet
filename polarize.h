#ifndef _POLARIZE_H_
#define _POLARIZE_H_

#include "ability.h"
#include <iostream>

class Polarize: public Ability {
    public:
    bool use(Link &targetLink) override;
    bool use(Cell &targetCell) override;
    Polarize(Player* player);
    std::string getName() const override;
};

#endif
