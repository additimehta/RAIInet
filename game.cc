#include "subject.h"
#include "board.h"
#include <vector>
#include <memory>

class Game: public Subject {
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
};