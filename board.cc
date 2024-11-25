#include "board.h"

using namespace std;

Board::Board(int height, int width) : height{height}, width{width} {
    grid = vector<std::vector<Cell>>(height, std::vector<Cell>(width));
}

Cell Board::getCell(int row, int col) {
    return grid[row][col];
}

void Board::initializeBoard() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = Cell();
        }
    }
}

void Board::moveLink(Link link, char d) {
    bool found = false;
    int currentRow = -1, currentCol = -1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j].getLink() == link) {  // using link comparator operator
                currentRow = i;
                currentCol = j;
                found = true;
            }
        }
    }

    int newRow = currentRow;
    int newCol = currentCol;


    switch (d) {
        case 'u': newRow--; break;
        case 'd': newRow++; break;
        case 'l': newCol--; break;
        case 'r': newCol++; break;
    }

    grid[currentRow][currentCol].removeLink();
    grid[newRow][newCol].placeLink(link);

}