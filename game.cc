#include "game.h"
#include "textobserver.h"
#include <sstream>


using namespace std;

Game::Game(const string a1, const string a2, const vector<string>& links1, const vector<string>& links2) : board(std::make_unique<Board>(8, 8)), currentPlayerIndex(0), gameOver(false) {
    players.push_back(std::make_unique<Player>(0, 0, 0));
    players.push_back(std::make_unique<Player>(1, 0, 0));
    initalizeAbilites(a1, a2);
    initalizeLinks(players[0].get(), links1);
    initalizeLinks(players[1].get(), links2);
    initializeBoard();
}//work on the game ctor 





Game::~Game() {}


/*
void Game::startGame() {
    players.push_back(std::make_unique<Player>(1, 0, 0));
    players.push_back(std::make_unique<Player>(2, 0, 0));
}

*/

void Game::initalizeLinks(Player *player, vector<string> linksString) {
    for (int i = 0; i < 8; ++i) {
        string link = linksString[i];
        string type(1, link[0]);
        int strength = link[1] - '0';
        if (player == getPlayer(0)) {
            player->addLink(std::make_unique<Link>(type, strength, false, player, 'a' + i));
        }
        else {
            player->addLink(std::make_unique<Link>(type, strength, false, player, 'A' + i));
        }
    }
}

void Game::initalizeAbilites(const string a1, const string a2) {
    players[0]->addAbility(a1);
    players[1]->addAbility(a2);  
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
            board->getCell(1, i)->placeLink(players[0]->getLink(i));
        } else {
            board->getCell(0, i)->placeLink(players[0]->getLink(i));
        }
    }
    for(int i = 0; i < width; ++i) {
        if(i == 3 || i == 4) {
            board->getCell(6, i)->placeLink(players[1]->getLink(i));
        } else {
            board->getCell(7, i)->placeLink(players[1]->getLink(i));
        }
    }
}

bool Game::moveLink(Link *link, char d) {                       // returns true if move was successful, false if not 
    if(link->getOwner()->getPlayerID() != this->currentPlayerIndex) {
        return false;
    }


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

    if (!found) return false;

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
        //reveal link to other player here;

        if (this->currentPlayerIndex == 0) {       // player 1
            if(board->getCell(newRow, newCol)->getIsServerPort()) { // if it is a server port, download to enemy
                if(link->getType() == "V") {
                    this->players[1]->setDownloadedViruses(1 + this->players[1]->getDownloadedViruses());
                } else {
                    this->players[1]->setDownloadedData(1  + this->players[1]->getDownloadedData());
                }
            } else {
                if(link->getType() == "V") {                            // else download to self
                    this->players[0]->setDownloadedViruses(1 + this->players[0]->getDownloadedViruses());
                } else {
                    this->players[0]->setDownloadedData(1 + this->players[0]->getDownloadedData());
                }
            }
        } else {
            if(board->getCell(newRow, newCol)->getIsServerPort()) { // if it is a server port, download to enemy
                if(link->getType() == "V") {
                    this->players[0]->setDownloadedViruses(1 + this->players[0]->getDownloadedViruses());
                } else {
                    this->players[0]->setDownloadedData(1 + this->players[0]->getDownloadedData());
                }
            } else {
                if(link->getType() == "V") {                            // else download to self
                    this->players[1]->setDownloadedViruses(1 + this->players[1]->getDownloadedViruses());
                } else {
                    this->players[1]->setDownloadedData(1 + this->players[1]->getDownloadedData());
                }
            }
        }

        board->getCell(currentRow, currentCol)->removeLink();
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

         //reveal link to other player here;

        // Remove the link from the current position
        board->getCell(currentRow, currentCol)->removeLink();
    }
    return true;
}

int Game::checkWin() {
    if(this->players[1]->getDownloadedData() >= 4 || this->players[1]->getDownloadedViruses() >= 4) {           // 2 = player 2 wins
        return 2;
    } else if (this->players[0]->getDownloadedData() >= 4 || this->players[0]->getDownloadedViruses() >= 4) {    // 1 = player 1 wins
        return 1;  
    } else {
        return 0;           // 0 = no one has won
    }
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
        int linkIndex = linkChar - 'A';
        return getPlayer(1)->getLink(linkIndex);
    }
    else {
        return nullptr;
    }
}

void Game::addPlayer(std::unique_ptr<Player> player) {
    players.emplace_back(std::move(player));
}

void Game::switchTurn() {       // need to add funcitonality to only iterate over "alive" players
    currentPlayerIndex++;
    if (currentPlayerIndex >= getPlayerCount()) {
        currentPlayerIndex = 0;
    }
}

void Game::gameLoop() {
    std::string command;

    while(std::cin >> command) {

        if (command == "move") {
            char linkChar;
            char direction;
            std::cin >> linkChar >> direction;
            Link *link = charToLink(linkChar);
            if (moveLink(link, direction)) notifyObservers();
            else std::cout << "Move not valid";
        }
        else if (command == "abilities") {
            // display abilities to display
        }
        else if (command == "ability") {
            int abilityID;
            std::cin >> abilityID;
        
            int row;
            int col;
            char linkChar;
            if (std::cin >> row >> col) {  // inputted a target cell
                Cell *cell = getBoard()->getCell(row, col);
                getPlayer(currentPlayerIndex)->useAbility(abilityID, *cell);
            }
            else if (std::cin >> linkChar) { // inputted a target link
                Link *link = charToLink(linkChar);
                getPlayer(currentPlayerIndex)->useAbility(abilityID, *link);
            }
            else {
                std::cout << "Ability command not correct";
            }
        }
        else if (command == "board") {
            notifyObservers();
        }
        else if (command == "sequence") {
            string file;
            std::cin >> file;
            // execute sequence inside file
        }
        else if (command == "quit") {
            break;
        }
        // add checkWin() here
    }
}
