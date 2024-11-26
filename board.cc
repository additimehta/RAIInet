 #include "board.h"

using namespace std;

Board::Board(int height, int width) : height{height}, width{width} {
    grid = vector<std::vector<Cell>>(height, std::vector<Cell>(width));
}

Cell Board::getCell(int row, int col) {
    return grid[row][col];
}

int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
} 

/*
void Board::initializeBoard() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if((i == 0 && j == 3 ) || (i == 0 && j == 4 ) || (i == 7 && j == 4 ) || (i == 7 && j == 3 )) {                  //hardcode: server ports
                grid[i][j] = Cell(nullptr, true);
            } else {
                grid[i][j] = Cell(nullptr, false);
            }
        }
    }
}

void Board::moveLink(Link *link, char d) {
    bool found = false;
    int currentRow = -1, currentCol = -1;

    for (int i = 0; i < height; ++i) {                                                        // finding where the selecting link is
        for (int j = 0; j < width; ++j) {
            if (grid[i][j].getLink() == link) {  // comparing addresses of links
                currentRow = i;
                currentCol = j;
                found = true;
            }
        }
    }

    int newRow = currentRow;
    int newCol = currentCol;

    switch (d) {                                                                              // calculating position where link wants to move
        case 'u': newRow--; break;
        case 'd': newRow++; break;
        case 'l': newCol--; break;
        case 'r': newCol++; break;
    }

    if(newCol < 0 || newCol > 7) {                                                             // check if position is out of bounds
        newRow = currentRow;
        newCol = currentCol; // moving out of bounds
    }

    if(newRow < 0 || newRow > 7 || grid[newRow][newCol].getIsServerPort()) {                  // check if position is a server port
        grid[currentRow][currentCol].removeLink();
    }

    // checking for if the new row and column have a link, if so, battle the two and place the winner in the new cell.
    if (grid[newRow][newCol].getLink() == nullptr) {
        grid[newRow][newCol].placeLink(link);
        grid[currentRow][currentCol].removeLink();
    } else {
        grid[newRow][newCol].placeLink([currentRow][currentCol].getLink().battle(grid[newRow][newCol]));
        grid[currentRow][currentCol].removeLink();
    }
}
*/
