#include "polarize.h"

void Polarize::use(Link &targetLink) {
    if (targetLink.getType() == "D") {
        targetLink.setType("V");
    }
    else {
        targetLink.setType("D");
    }
}
