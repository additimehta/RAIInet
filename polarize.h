#ifndef _POLARIZE_H_
#define _POLARIZE_H_

#include "ability.h"

class Polarize: public Ability {
    void use(Link &targetLink) override;
};

#endif
