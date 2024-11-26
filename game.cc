#include "game.h"
#include <sstream>

using namespace std;

Game::Game() : board(std::make_unique<Board>(8, 8)), currentPlayerIndex(0), gameOver(false) {}

Game::~Game() {}

void Game::startGame() {
    board = std::make_unique<Board>(8, 8);
    void initializeBoard();
    players.push_back(std::make_unique<Player>(1));
    players.push_back(std::make_unique<Player>(2));

    initalizeLinks(players[0]);
    initalizeLinks(players[1]);
    notifyObservers();
}

void Game::initalizeLinks(std::unique_ptr<Player>& player) {
    player->addLink(std::make_unique<Link>("D", 1, false, player.get()));
    player->addLink(std::make_unique<Link>("D", 2, false, player.get()));
    player->addLink(std::make_unique<Link>("D", 3, false, player.get()));
    player->addLink(std::make_unique<Link>("D", 4, false, player.get()));
    player->addLink(std::make_unique<Link>("V", 1, false, player.get()));
    player->addLink(std::make_unique<Link>("V", 2, false, player.get()));
    player->addLink(std::make_unique<Link>("V", 3, false, player.get()));
    player->addLink(std::make_unique<Link>("V", 4, false, player.get()));
}

void Game::initializeBoard() {
    int height = board->getHeight();
    int width = board->getWidth();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Cell *cell = board->getCell(i, j);
            if ((i == 0 && j == 3) || (i == 0 && j == 4) || (i == 7 && j == 4) || (i == 7 && j == 3)) {
                cell->setIsServerPort(true);
            }
        }
    }

    for(int i = 0; i < width; ++i) {
        if(i == 3 || i == 4) {
            board->getCell(0, i)->placeLink(players[0]->getLinks()->at(i).get());
        } else {
            board->getCell(1, i)->placeLink(players[0]->getLinks()->at(i).get());
        }
    }
    for(int i = 0; i < width; ++i) {
        if(i == 3 || i == 4) {
            board->getCell(6, i)->placeLink(players[1]->getLinks()->at(i).get());
        } else {
            board->getCell(7, i)->placeLink(players[1]->getLinks()->at(i).get());
        }
    }
}

bool Game::moveLink(Link *link, char d) {                       // returns true if move was successful, false if not 
    bool found = false;
    int currentRow = -1, currentCol = -1;

    
    for (int i = 0; i < board->getHeight(); ++i) {              // Finding the current position of the link
        for (int j = 0; j < board->getWidth(); ++j) {
            if (board->getCell(i, j)->getLink() == link) {
                currentRow = i;
                currentCol = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return;

    int newRow = currentRow;
    int newCol = currentCol;

    switch (d) {
        case 'u': newRow--; break;
        case 'd': newRow++; break;
        case 'l': newCol--; break;
        case 'r': newCol++; break;
    }

    if (newRow < 0 || newRow > 7 || board->getCell(newRow, newCol)->getIsServerPort() || newCol < 0 || newCol > 7) {       // If the move is invalid, return without moving the link
        if (newCol < 0 || newCol > 7) {         // cannot ever move out of columns
            return false;
        }
        if (this->currentPlayerIndex == 0) {       // if it is player 1
            if (newRow < 1) {                     // cannot move into own server ports  (Row 0) or out of map (Row -1)
                return false;
            }
        } else {                                   // if it is player 2
            if (newRow > 6) {                     // cannot move into own server ports (Row (7) or out of map (Row 8+)
                return false;       
            }
        }
    }


    if (newRow < 0 || newRow > 7 || board->getCell(newRow, newCol)->getIsServerPort()) {
        board->getCell(currentRow, currentCol)->removeLink();

        if (this->currentPlayerIndex == 0) {       // player 1
            if(board->getCell(newRow, newCol)->getIsServerPort()) { // if it is a server port, download to enemy
                if(link->getType() == "V") {
                    this->players[1]->setDownloadedViruses(link->getStrength() + this->players[1]->getDownloadedViruses());
                } else {
                    this->players[1]->setDownloadedData(link->getStrength()  + this->players[1]->getDownloadedData());
                }
            } else {
                if(link->getType() == "V") {                            // else download to self
                    this->players[0]->setDownloadedViruses(link->getStrength() + this->players[0]->getDownloadedViruses());
                } else {
                    this->players[0]->setDownloadedData(link->getStrength() + this->players[0]->getDownloadedData());
                }
            }
        } else {
            if(board->getCell(newRow, newCol)->getIsServerPort()) { // if it is a server port, download to enemy
                if(link->getType() == "V") {
                    this->players[0]->setDownloadedViruses(link->getStrength() + this->players[0]->getDownloadedViruses());
                } else {
                    this->players[0]->setDownloadedData(link->getStrength()  + this->players[0]->getDownloadedData());
                }
            } else {
                if(link->getType() == "V") {                            // else download to self
                    this->players[1]->setDownloadedViruses(link->getStrength() + this->players[1]->getDownloadedViruses());
                } else {
                    this->players[1]->setDownloadedData(link->getStrength() + this->players[1]->getDownloadedData());
                }
            }
        }
        
    }

    Link *newLink = board->getCell(newRow, newCol)->getLink();

    // If the new cell is empty, place the moving link there
    if (newLink == nullptr) {
        board->getCell(newRow, newCol)->placeLink(link);
        board->getCell(currentRow, currentCol)->removeLink();
    }
    else {
        // Compare strengths and place the stronger link
        if (link->getStrength() > newLink->getStrength()) {
            board->getCell(newRow, newCol)->placeLink(link);
        }
        else {
            board->getCell(newRow, newCol)->placeLink(newLink);
        }

        // Remove the link from the current position
        board->getCell(currentRow, currentCol)->removeLink();
    }

    //!!!!!!!!!!!! need to check for win after moving !!!!!!!!!!!!!!!!!

}

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

