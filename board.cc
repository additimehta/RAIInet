#include "board.h"

using namespace std;

Board::Board(int height, int width) : height{height}, width{width} {
    grid.resize(height);
    for (int i = 0; i < height; ++i) {
        grid[i].resize(width);
        for (int j = 0; j < width; ++j) {
            grid[i][j] = std::make_unique<Cell>();
        }
    }
}

Cell* Board::getCell(int row, int col) const {
    return grid[row][col].get();
}
int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
} 


vector<Cell*> Board::getEmptyCells() const {
    vector<Cell*> emptyCells;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Cell* cell = grid[i][j].get();
            if (cell->getLink() == nullptr && !cell->getIsServerPort()) {
                emptyCells.push_back(cell);
            }
        }
    }

    return emptyCells;
}
