#include "scan.h"
#include "player.h"

Scan::Scan(Player* player): Ability {player} {}


bool Scan::use(Link &targetLink) {

    if(isUsed || targetLink.getOwner()->getPlayerID() == player->getPlayerID()) {
        return false;
    }

    targetLink.setIsRevealed(true);
    this->isUsed = true;
    markUsed();
    return true;

}

bool Scan::use(Cell &targetCell) {
    return false;
}


std::string Scan::getName() const {
    return "Scan";
}