#include "linkboost.h"

Linkboost::Linkboost(Player* player): Ability {player} {}


bool Linkboost::use(Link &targetLink) {
    targetLink.setAbilityStatus(1);
    return true;
}

bool Linkboost::use(Cell &targetCell) {
    std::cout << "Linkboost ability can only be used on Links!";
    return false;
}

std::string Linkboost::getName() const {
    return "Link boost";
}