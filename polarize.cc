#include "polarize.h"



Polarize::Polarize(Player* player) {
    this->player = player;
}


void Polarize::use(Link &targetLink) {
    if (targetLink.getType() == "D") {
        targetLink.setType("V");
    }
    else {
        targetLink.setType("D");
    }
}
