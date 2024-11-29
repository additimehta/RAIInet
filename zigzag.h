#ifndef _ZIGZAG_H_
#define _ZIGZAG_H_

#include "ability.h"
#include <iostream>

class Zigzag: public Ability {
    public:
        Zigzag(Player* player);
        bool use(Link &targetLink) override;
        std::string getName() const override;
};

#endif
