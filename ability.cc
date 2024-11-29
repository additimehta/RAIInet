#include "ability.h"

Ability::Ability(Player* player) : player(player), isUsed(false) {}
Ability::~Ability() {}
bool Ability::hasBeenUsed() const { return isUsed; }
void Ability::markUsed() { isUsed = true; }
bool Ability::use(Link &targetLink) {return false;}
bool Ability::use(Cell &targetCell) {return false;}
