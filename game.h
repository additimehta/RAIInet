#include "subject.h"
#include "board.h"
#include <vector>
#include <memory>
#include <string>

class Game: public Subject {
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;

    public:
        //getters
        Board *getBoard() const;
        Player *getPlayer(const int playerID) const;
        int getPlayerCount() const;
        int getCurrentPlayerIndex() const;

        void addPlayer(std::unique_ptr<Player> player);   // take over ownership of player

        //ctor
        Game(); 

        void startGame();
        void processCommand(std::string command);
        void switchTurn();
};
