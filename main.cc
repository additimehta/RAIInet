#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "ability.h"
#include "board.h"
#include "cell.h"
#include "link.h"
#include "observer.h"
#include "player.h"
#include "subject.h"
#include "textobserver.h"
#include "game.h"

using namespace std;

vector<string> parseLinks(const string &filename) {
    ifstream file(filename);
    vector<string> links;
    string link;
    while (file >> link) {
        links.push_back(link);
    }
    return links;
}


int main(int argc, char* argv[]) {

    std::vector<Observer*> observers;

    std::string abilities1 = "LFDSP";
    std::string abilities2 = "LFDSP";
    vector<string> links1 = {"V1", "V2", "V3", "V4", "D1", "D2", "D3", "D4"};
    vector<string> links2 = {"V1", "V2", "V3", "V4", "D1", "D2", "D3", "D4"};
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-ability1" && i + 1 < argc) {
            abilities1 = argv[++i];

        } else if (arg == "-ability2" && i + 1 < argc) {
            abilities2 = argv[++i];

        } else if (arg == "-link1" && i + 1 < argc) {
            vector<string> links = parseLinks(argv[++i]);
            if (links.size() == 8) { // valid links in file
                links1 = links;
            }
        } else if (arg == "-link2" && i + 1 < argc) {
            vector<string> links = parseLinks(argv[++i]);
            if (links.size() == 8) { // valid links in file
                links2 = links;
            }
        } else if (arg == "-graphics") {
            // enable graphics
        }
    }




    Game game;
    game.startGame();
    game.initalizeLinks(game.getPlayer(0), links1);
    game.initalizeLinks(game.getPlayer(1), links2);
    game.initializeBoard();
    game.notifyObservers();
    game.gameLoop();
    for (Observer* observer : observers) {
        delete observer;
    }

}
