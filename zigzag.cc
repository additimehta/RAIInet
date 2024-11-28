#include "zigzag.h"
#include "player.h"

Zigzag::Zigzag(Player* player): Ability {player} {}


bool Zigzag::use(Link &targetLink) {
    targetLink.setAbilityStatus(2);
}

string Zigzag::getName() const {
    return "Zigzag";
}