#ifndef _FIREWALL_H_
#define _FIREWALL_H_

#include "ability.h"
#include <iostream>

class Firewall: public Ability {
    public:
        Firewall(Player* player);
        bool use(Cell &targetCell) override;
};

#endif
