#include "zigzag.h"
#include "player.h"

Zigzag::Zigzag(Player* player): Ability {player} {}


bool Zigzag::use(Link &targetLink) {
    if(isUsed) {
        std::cout << "Zigzag ability has already been used!" << std::endl;
        return false;
    }

    targetLink.setAbilityStatus(2);
    markUsed();
    return true;

}


bool Zigzag::use(Cell &targetCell) {
    std::cout << "Zigzag ability can only be used on Links!";
    return false;
}

std::string Zigzag::getName() const {
    return "Zigzag";
}