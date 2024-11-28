#include "linkboost.h"

class Player;

Linkboost::Linkboost(Player* player): Ability {player} {}


bool Linkboost::use(Link &targetLink) {
    targetLink.setAbilityStatus(1);
    return true;
}

string Linkboost::getName() const {
    return "Link boost";
}