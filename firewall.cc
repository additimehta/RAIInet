#include "firewall.h"
#include "player.h"

Firewall::Firewall(Player *player): Ability{player} {}


bool Firewall::use(Cell &targetCell) {
    if(isUsed) {
        std::cout << "Firewall ability has already been used!" << std::endl;
        return false;
    }

    if (targetCell.getIsServerPort() || targetCell.getLink() != nullptr || targetCell.isAmplifier || targetCell.isFirewall) {
        return false;
    }
    targetCell.isFirewall = true;
    if (player->getPlayerID() == 0) {
        targetCell.underneathLetter = 'm';
    }
    else {
        targetCell.underneathLetter = 'w';
    }
    markUsed();
    return true;
}

bool Firewall::use(Link &targetLink) {
    std::cout << "Firewall ability can only be used on Cells!";
    return false;
}

std::string Firewall::getName() const {
    return "Firewall";
}
