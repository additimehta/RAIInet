#include "subject.h"
#include "board.h"
#include <vector>
#include <memory>
#include <string>

class Game: public Subject {
    vector<Observer*> observers;
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
    bool gameOver;


    public:
        //getters
        Board *getBoard() const;
        Player *getPlayer(int id) const;
        int getPlayerCount() const;
        int getCurrentPlayerIndex() const;

        //ctor
        Game(); 
        ~Game();

        void startGame();
        void processCommand(std::string command);
        void switchTurn();
        void initializeBoard();
        void moveLinks(Link *link, char d);
};

