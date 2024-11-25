#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <vector>
#include "cell.h"

using namespace std;

class Board {
    int height;
    int width;

    vector<vector<Cell>> grid;

    public:
        Cell getCell(int row, int col);

        Board(int height, int width);

        void initializeBoard();
        void moveLink(Link link, char d); //u d r l

};

#endif
