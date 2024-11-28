#include "warpshift.h"
#include "link.h"
#include "player.h"
#include "cell.h"


WarpShift::WarpShift(Player* player) : Ability(player) {}


bool WarpShift::use(Link &targetLink) {
    vector<Cell*> emptyCells = targetLink.getOwner()->getBoard()->getEmptyCells();
    if (emptyCells.empty()) {
        std::cout << "No empty cells available for Warp Shift!" << std::endl;
        return false;
    }

    srand(time(0));
    int randomIndex = rand() % emptyCells.size();
    Cell* newCell = emptyCells[randomIndex];
    targetLink.setCell(newCell);
    return true;
}


