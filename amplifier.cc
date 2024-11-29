#include "amplifier.h"

Amplifier::Amplifier(Player *player): Ability{player} {}


bool Amplifier::use(Cell &targetCell) {
    if(isUsed) {
        std::cout << "Amplifier ability has already been used!" << std::endl;
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
    std::cout << "Polarize ability can only be used on Cells!";
    return false;
}

std::string Amplifier::getName() const {
    return "Amplifier";
}


