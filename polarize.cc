#include "polarize.h"



Polarize::Polarize(Player* player): Ability {player} {}


bool Polarize::use(Link &targetLink) {
    if (targetLink.getType() == "D") {
        targetLink.setType("V");
    }
    else {
        targetLink.setType("D");
    }
    this->isUsed = true;
    return true;
}

string Polarize::getName() const {
    return "Polarize";
}