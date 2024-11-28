#include "firewall.h"
#include "player.h"

Firewall::Firewall(Player *player): Ability{player} {}


bool Firewall::use(Cell &targetCell) {
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
    isUsed = true;
    return true;
}

string Firewall::getName() const {
    return "Firewall";
}