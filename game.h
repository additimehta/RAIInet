#include "subject.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <memory>
#include <string>
#include "link.h"

class Game: public Subject {
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
    
    Link *charToLink(char linkChar);

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
        bool processCommand(std::string command);        // returns true if successful, otherwise false
        void switchTurn();
};
