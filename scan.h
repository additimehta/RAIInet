#ifndef _SCAN_H_
#define _SCAN_H_

#include "ability.h"
#include <iostream>

class Scan: public Ability {
    public:
    bool use(Link &targetLink) override;
    bool use(Cell &targetCell) override;
    Scan(Player* player);
    std::string getName() const override;
};

#endif
