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


int main() {
    std::string command;
    std::vector<Observer*> observers;

    while(std::cin >> command) {
        if(command == "move") {
            char linkChar;
            char direction;
            std::cin >> linkChar >> direction;
            if (iss.fail()) {
                return false;
            }
            Link *link = charToLink(linkChar);
            moveLink(link, direction);
        }else if(action == "abilities") {
            //display abiltiies
        } else if (action == "ability") {
            int abilityID;
            std::cin >> abilityID;

            int row;
            int col;
            char linkChar;
            if (std::cin >> row >> col) {  // inputted a cell
                Cell *cell = getBoard()->getCell(row, col);
                getPlayer(currentPlayerIndex)->useAbility(abilityID, *cell);
            }
            else if (std::cin >> linkChar) {
                Link *link = charToLink(linkChar);
                getPlayer(currentPlayerIndex)->useAbility(abilityID, *link);
            }
        }else if (action == "board") {
        // display board
        }else if (action == "sequence") {
        string file;
        iss >> file;
        if (iss.fail() || file.empty()) {
            return false;
        }
        // execute sequence inside file
        }else if (action == "quit") {
            break;
        }

    }
    
    for (Observer* observer : observers) {
    delete observer;
  }

}
