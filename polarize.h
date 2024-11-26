#include "ability.h"

class Polarize: public Ability {
    void use(Link &targetLink) override;
};