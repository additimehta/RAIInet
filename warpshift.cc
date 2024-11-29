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
    Board *board = player->getBoard();
    int currentRow;
    int currentCol;
    bool found;
    for (int i = 0; i < board->getHeight(); ++i) {              // Finding the current position of the link
        for (int j = 0; j < board->getWidth(); ++j) {
            if (board->getCell(i, j)->getLink() == &targetLink) {
                currentRow = i;
                currentCol = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    Cell *currentCell = board->getCell(currentRow, currentCol);
    currentCell->removeLink();
    newCell->placeLink(&targetLink);
    markUsed();
    return true;
}

bool WarpShift::use(Cell &targetCell) {
    std::cout << "Warp Shift ability can only be used on Links!";
    return false;
}

std::string WarpShift::getName() const {
    return "Warp shift";
}

