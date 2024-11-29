#ifndef _WARPSHIFT_H_
#define _WARPSHIFT_H_

#include "ability.h"
#include <iostream>

class WarpShift: public Ability {
    public:
        WarpShift(Player* player);
        bool use(Link &targetLink) override;
        bool use(Cell &targetCell) override;
        std::string getName() const override;
};

#endif
