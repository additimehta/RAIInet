#ifndef _WARPSHIFT_H_
#define _WARPSHIFT_H_

#include "ability.h"
#include <iostream>

class WarpShift: public Ability {
    public:
        WarpShift(Player* player);
        bool use(Link &targetLink) override;
};

#endif
