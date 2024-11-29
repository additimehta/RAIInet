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

bool Scan::use(Cell &targetCell) {
    std::cout << "Scan ability can only be used on Links!";
    return false;
}


std::string Scan::getName() const {
    return "Scan";
}