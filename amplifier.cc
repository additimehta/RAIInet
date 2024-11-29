#include "amplifier.h"

Amplifier::Amplifier(Player *player): Ability{player} {}


bool Amplifier::use(Cell &targetCell) {
    if(isUsed) {
        return false;
    }

    if (targetCell.getIsServerPort() || targetCell.getLink() != nullptr || targetCell.isAmplifier || targetCell.isFirewall) {
        return false;
    }
    
    targetCell.isAmplifier = true;
    targetCell.underneathLetter = '!';
    markUsed();
    return true;
}


bool Amplifier::use(Link &targetLink) {
    return false;
}

std::string Amplifier::getName() const {
    return "Amplifier";
}


