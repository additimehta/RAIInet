 #include "board.h"

using namespace std;

Board::Board(int height, int width) : height{height}, width{width} {
    grid = vector<vector<unique_ptr<Cell>>>(height, vector<unique_ptr<Cell>>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = make_unique<Cell>();
        }
    }
}

Cell* Board::getCell(int row, int col) {
    return grid[row][col].get();
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
                board.getCell(i, j) = Cell(nullptr, true);
            } else {
                board.getCell(i, j) = Cell(nullptr, false);
            }
        }
    }

    for (int i = 0; i < height; ++i) {

    }

}

void Board::moveLink(Link *link, char d) {
    bool found = false;
    int currentRow = -1, currentCol = -1;

    for (int i = 0; i < height; ++i) {                                                        // finding where the selecting link is
        for (int j = 0; j < width; ++j) {
            if (board.getCell(i, j).getLink() == link) {  // comparing addresses of links
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

    //move valid checking to its own method, so that the main class can tell player to try again if failed

    if(newCol < 0 || newCol > 7) {                                                             // check if position is out of bounds
        newRow = currentRow;
        newCol = currentCol; // moving out of bounds
    }


    if( //player one) {
        if (newRow < 0 || (board.getCell(newRow, newCol).getIsServerPort() && newRow == 0)) {
            newRow = currentRow;
            newCol = currentCol; // moving out of bounds
        }
    } else {
        if (newRow > 7 || (board.getCell(newRow, newCol).getIsServerPort() && newRow == 7)) {
            newRow = currentRow;
            newCol = currentCol; // moving out of bounds
        }
    }
    // add bounds to make sure link does not move into own server port & its own border



    if(newRow < 0 || newRow > 7 || board.getCell(newRow, newCol).getIsServerPort()) {                  // check if position is a server port
        board.getCell(currentRow, currentCol).removeLink();

        if(board.getCell(newRow, newCol).getIsServerPort()) {
            if(newRow == 0) {
                //player1 download
            } else {
                //player2 download
            }
        }

        if (newRow < 0) {
            //player1 download
        } else {
            //player2 download
        }

    }

    // checking for if the new row and column have a link, if so, battle the two and place the winner in the new cell.
    if (board.getCell(newRow, newCol).getLink() == nullptr) {
        board.getCell(newRow, newCol).placeLink(link);
        board.getCell(currentRow, currentCol).removeLink();
    } else {
        board.getCell(newRow, newCol).placeLink(board.getCell(currentRow, currentCol).getLink().battle(board.getCell(newRow, newCol)));
        board.getCell(currentRow, currentCol).removeLink();
    }
}
*/