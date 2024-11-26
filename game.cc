#include "game.h"
#include <sstream>

using namespace std;

Board *Game::getBoard() const {
    return board.get();
}

Player *Game::getPlayer(const int playerID) const {   // playerID must be 0-indexed
    return players.at(playerID).get();
}

int Game::getPlayerCount() const {
    return players.size();
}

int Game::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

Link *Game::charToLink(char linkChar) {
    if ('a' <= linkChar && linkChar <= 'g') {
        // player 1
        int linkIndex = linkChar - 'a';
        return getPlayer(0)->getLink(linkIndex);
    }
    else if ('A' <= linkChar && linkChar <= 'G') {
        // player 2
        int linkIndex = linkChar - 'a';
        return getPlayer(1)->getLink(linkIndex);
    }
    else {
        return nullptr;
    }
}

void Game::addPlayer(std::unique_ptr<Player> player) {
    int current_size = getPlayerCount();
    players.emplace_back(player);
}

void Game::switchTurn() {       // need to add funcitonality to only iterate over "alive" players
    currentPlayerIndex++;
    if (currentPlayerIndex >= getPlayerCount()) {
        currentPlayerIndex = 0;
    }
}

bool Game::processCommand(string command) {
    std::istringstream iss(command);
    std::string action;
    iss >> action;
    if (action == "move") {
        char linkChar;
        char direction;
        iss >> linkChar >> direction;
        if (iss.fail()) {
            return false;
        }
        Link *link = charToLink(linkChar);
        moveLink(link, direction);
    }
    else if (action == "abilities") {
        // display abilities to display
    }
    else if (action == "ability") {
        int abilityID;
        iss >> abilityID;
        if (iss.fail()) {
            return false;
        }

        int row;
        int col;
        char linkChar;
        if (iss >> row >> col) {  // inputted a cell
            Cell *cell = getBoard()->getCell(row, col);
            getPlayer(currentPlayerIndex)->useAbility(abilityID, *cell);
        }
        else if (iss >> linkChar) {
            Link *link = charToLink(linkChar);
            getPlayer(currentPlayerIndex)->useAbility(abilityID, *link);
        }
        else {
            return false;
        }
    }
    else if (action == "board") {
        // display board
    }
    else if (action == "sequence") {
        string file;
        iss >> file;
        if (iss.fail() || file.empty()) {
            return false;
        }
        // execute sequence inside file
    }
    else if (action == "quit") {
        // quit game (return false?)
    }
    else {
        return false;
    }
    return true;
}