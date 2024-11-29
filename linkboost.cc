#include "linkboost.h"

Linkboost::Linkboost(Player* player): Ability {player} {}


bool Linkboost::use(Link &targetLink) {
    if(isUsed) {
        std::cout << "Scan ability has already been used!" << std::endl;
        return false;
    }
    targetLink.setAbilityStatus(1);
    markUsed();
    return true;
    
}

bool Linkboost::use(Cell &targetCell) {
    std::cout << "Linkboost ability can only be used on Links!";
    return false;
}

std::string Linkboost::getName() const {
    return "Link boost";
}