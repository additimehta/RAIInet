#include "polarize.h"


Polarize::Polarize(Player* player): Ability {player} {}


bool Polarize::use(Link &targetLink) {

    if(isUsed) {
        std::cout << "Polarize ability has already been used!";
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

std::string Polarize::getName() const {
    return "Polarize";
}