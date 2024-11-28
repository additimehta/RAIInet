#include "linkboost.h"
#include "player.h"

Linkboost::Linkboost(Player* player): Ability {player} {}


bool Linkboost::use(Link &targetLink) {
    targetLink.setAbilityStatus(1);
}

string Linkboost::getName() const {
    return "Link boost";
}