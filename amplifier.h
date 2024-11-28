#ifndef _AMPLIFIER_H_
#define _AMPLIFIER_H_

#include "ability.h"
#include <iostream>

class Amplifier: public Ability {
    public:
        Amplifier(Player* player);
        bool use(Cell &targetCell) override;
        string getName() const override;
};

#endif
