#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ability.h"
#include "board.h"
#include "cell.h"
#include "link.h"
#include "observer.h"
#include "player.h"
#include "subject.h"
#include "textobserver.h"
#include "game.h"


int main(int argc, char* argv[]) {

    std::vector<Observer*> observers;

    std::string abilities1 = "LFDSP";
    std::string abilities2 = "LFDSP";
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-ability1" && i + 1 < argc) {
            abilities1 = argv[++i];
        } else if (arg == "-ability2" && i + 1 < argc) {
            abilities2 = argv[++i];
        }
    }


    Game game;
    game.startGame();
    game.gameLoop();
    for (Observer* observer : observers) {
        delete observer;
    }

}
