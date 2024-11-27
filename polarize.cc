#include "polarize.h"



Polarize::Polarize(Player* player): Ability {player} {}


void Polarize::use(Link &targetLink) {
    if (targetLink.getType() == "D") {
        targetLink.setType("V");
    }
    else {
        targetLink.setType("D");
    }
    this->isUsed = true;
}
