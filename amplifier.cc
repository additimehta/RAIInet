#include "amplifier.h"
#include "player.h"

Amplifier::Amplifier(Player *player): Ability{player} {}


bool Amplifier::use(Cell &targetCell) {
    if (targetCell.getIsServerPort() || targetCell.getLink() != nullptr || targetCell.isAmplifier || targetCell.isFirewall) {
        return false;
    }
    targetCell.isAmplifier = true;
    targetCell.underneathLetter = '!';
    isUsed = true;
    return true;
}
