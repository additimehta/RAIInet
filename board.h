#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <vector>
#include <memory>
#include "cell.h"

using namespace std;

class Board {
    int height;
    int width;

    vector<vector<unique_ptr<Cell>>> grid;

    public:
        Cell* getCell(int row, int col) const;

        int getHeight();
        int getWidth();

        Board(int height, int width);

};

#endif
