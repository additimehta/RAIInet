#include "polarize.h"

void Polarize::use(Link &targetLink) {
    if (targetLink.getType() == "Data") {
        targetLink.setType("Virus");
    }
    else {
        targetLink.setType("Data");
    }
}
