#ifndef _POLARIZE_H_
#define _POLARIZE_H_

#include "ability.h"
#include <iostream>

class Polarize: public Ability {
    public:
    void use(Link &targetLink) override;
    Polarize(Player* player);
};

#endif
