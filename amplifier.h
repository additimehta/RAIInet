#ifndef _AMPLIFIER_H_
#define _AMPLIFIER_H_

#include "ability.h"
#include <iostream>

class Amplifier: public Ability {
    public:
        Amplifier(Player* player);
        bool use(Cell &targetCell) override;
        bool use(Link &targetLink) override;
        std::string getName() const override;
};

#endif
