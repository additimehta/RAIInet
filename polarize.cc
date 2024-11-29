#include "polarize.h"


Polarize::Polarize(Player* player): Ability {player} {}


bool Polarize::use(Link &targetLink) {

    if(isUsed) {
        return false;
    }

    if (targetLink.getType() == "D") {
        targetLink.setType("V");
    }
    else {
        targetLink.setType("D");
    }
    markUsed();
    return true;

}

bool Polarize::use(Cell &targetCell) {
    return false;
}

std::string Polarize::getName() const {
    return "Polarize";
}

