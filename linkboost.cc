#include "linkboost.h"

Linkboost::Linkboost(Player* player): Ability {player} {}


bool Linkboost::use(Link &targetLink) {
    if(isUsed) {
        return false;
    }
    targetLink.setAbilityStatus(1);
    markUsed();
    return true;
    
}

bool Linkboost::use(Cell &targetCell) {
    return false;
}

std::string Linkboost::getName() const {
    return "Link boost";
}
