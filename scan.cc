#include "scan.h"
#include "player.h"

Scan::Scan(Player* player): Ability {player} {}


bool Scan::use(Link &targetLink) {
    if (targetLink.getOwner()->getPlayerID() == player->getPlayerID()){
        return false;
    }
    targetLink.setIsRevealed(true);
    this->isUsed = true;
    return true;
}
