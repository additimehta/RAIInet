#ifndef _GAME_H_
#define _GAME_H_

#include "subject.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <memory>
#include <string>
#include <fstream> 
#include <sstream>
#include "subject.h"
#include "board.h"
#include "player.h"
#include "link.h"

using namespace std;


class Game: public Subject {
    vector<Observer*> observers;
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
    bool gameOver;

    Link *charToLink(char linkChar);

    public:
        //getters
        Board *getBoard() const;
        Player *getPlayer(const int playerID) const;
        int getPlayerCount() const;
        int getCurrentPlayerIndex() const;

        void addPlayer(std::unique_ptr<Player> player);   // take over ownership of player

        //ctor
        Game(const string a1, const string a2, const vector<string>& links1, const vector<string>& links2); 
        ~Game();

        //void startGame();

        bool processCommand(const string& cmd);
        void gameLoop();       // returns true if successful, otherwise false
        void extractFile(const string& filename);
        void switchTurn();
        void initializeBoard();
        bool moveLink(Link *link, char d);              // returns true if move was successful, false if not
        void initalizeLinks(Player *player, vector<string> linksString);
        void initalizeAbilites(string a1, string a2);
        int checkWin();                                 // 0 = no win, 1 = player one wins, 2 = player two wins
};

#endif
