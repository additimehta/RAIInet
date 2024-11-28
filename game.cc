#include "game.h"
#include "textobserver.h"
#include <sstream>

using namespace std;

Game::Game(const string a1, const string a2, const vector<string>& links1, const vector<string>& links2) : board(std::make_unique<Board>(8, 8)), currentPlayerIndex(0), gameOver(false) {
    players.push_back(std::make_unique<Player>(0, 0, 0, board.get()));
    players.push_back(std::make_unique<Player>(1, 0, 0, board.get()));
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


    if(link->getAbilityStatus() == 2) {     //zigzag

    /*
    1   2
      L         inputs for zig zag and what it moves it , 1 is top left etc.
    3   4
    
    */
        switch (d) {
            case 'u': newRow--; break;
            case 'd': newRow++; break;
            case 'l': newCol--; break;
            case 'r': newCol++; break;
            case '1': newRow--; newCol--; break;
            case '2': newRow--; newCol++; break;
            case '3': newRow++; newCol--; break;
            case '4': newRow++; newCol++; break;
            default:
                return false;
        }
    } else {                                //default
        switch (d) {
            case 'u': newRow--; break;
            case 'd': newRow++; break;
            case 'l': newCol--; break;
            case 'r': newCol++; break;
            default:
                return false;
        }
    }


    if(link->getAbilityStatus() == 1) { // link boost
        switch (d) {
            case 'u': newRow--; break;
            case 'd': newRow++; break;
            case 'l': newCol--; break;
            case 'r': newCol++; break;
            default:
                return false;
        }
    }

    /*
    HERE IS WHERE YOU ADD ABILTIES
    E.G if you are implementing zig zag
    change
    newCol & newRow to be diagonal, or you can add another case to switch above this,
    */



    // functionality for firewall and amplifier
    if (newCol >= 0 && newCol <= 7 && newRow >= 0 && newRow <= 7) {
        Cell *cell = board->getCell(newRow, newCol);
        // firewall
        if (cell->isFirewall) {
            if (link->getOwner()->getPlayerID() == 0 && cell->underneathLetter == 'w') { // opponents firewall
                link->setIsRevealed(true);
                if (link->getType() == "V") {     // owner downloads virus and turn is over
                    this->players[0]->setDownloadedViruses(1 + this->players[0]->getDownloadedViruses());
                    board->getCell(currentRow, currentCol)->removeLink();
                    return true;
                }
            }
            else if (link->getOwner()->getPlayerID() == 1 && cell->underneathLetter == 'm') { // opponents firewall
                link->setIsRevealed(true);
                if (link->getType() == "V") {     // owner downloads virus and turn is over
                    this->players[1]->setDownloadedViruses(1 + this->players[1]->getDownloadedViruses());
                    board->getCell(currentRow, currentCol)->removeLink();
                    return true;
                }
            }
        }
        // amplifier
        else if (cell->isAmplifier) {
            link->setStrength(link->getStrength() + 2);
        }
    }

    if (newCol < 0 || newCol > 7) {         // cannot ever move out of columns
        return false;
    }

    if (newRow < 0 && this->currentPlayerIndex == 0) {       // If the move is invalid, return without moving the link
        return false;
    }
    if (newRow > 7 && this->currentPlayerIndex == 1) {       // If the move is invalid, return without moving the link
        return false;
    }

    if( newRow >= 0 && newRow <= 7) {
        if (board->getCell(newRow, newCol)->getIsServerPort()) {        // check if own player tries to move in own server port
            if (this->currentPlayerIndex == 0 && newRow == 0) {
                return false;
            } else if (this->currentPlayerIndex == 1 && newRow == 7) {
                return false;
            }
        }
    }

    if (newRow < 0 || newRow > 7) {                                                                         // made it opponents end of board
        //reveal link to other player here;
        if (this->currentPlayerIndex == 0) {       // player 1
            if(link->getType() == "V") {                            // else download to self
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
        board->getCell(currentRow, currentCol)->removeLink();
    } else if (board->getCell(newRow, newCol)->getIsServerPort()) {                                             // made it opponents server port
        if (this->currentPlayerIndex == 0) {
            if(link->getType() == "V") {
                this->players[1]->setDownloadedViruses(1 + this->players[1]->getDownloadedViruses());
            } else {
                this->players[1]->setDownloadedData(1  + this->players[1]->getDownloadedData());
            }
        } else {
            if(link->getType() == "V") {
                this->players[0]->setDownloadedViruses(1 + this->players[0]->getDownloadedViruses());
            } else {
                this->players[0]->setDownloadedData(1 + this->players[0]->getDownloadedData());
            }
        }
        board->getCell(currentRow, currentCol)->removeLink();
    } else {                                                                                                // regular move
        Link *newLink = board->getCell(newRow, newCol)->getLink();

        // If the new cell is empty, place the moving link there
        if (newLink == nullptr) {
            board->getCell(newRow, newCol)->placeLink(link);
            board->getCell(currentRow, currentCol)->removeLink();
        }
        else {
            link->setIsRevealed(true);
            newLink->setIsRevealed(true);

        // Compare strengths and place the stronger link
        if(link->getOwner()->getPlayerID() == newLink->getOwner()->getPlayerID()) {
            return false;
        }


        if (link->getStrength() >= newLink->getStrength()) {
            board->getCell(newRow, newCol)->placeLink(link);
            if(link->getType() == "V") {                            // else download to self
                this->players[this->currentPlayerIndex]->setDownloadedViruses(1 + this->players[this->currentPlayerIndex]->getDownloadedViruses());
            } else {
                this->players[this->currentPlayerIndex]->setDownloadedData(1 + this->players[this->currentPlayerIndex]->getDownloadedData());
            }
        } else {
            board->getCell(newRow, newCol)->placeLink(newLink);

            int opp;

            if(this->currentPlayerIndex == 0) {
                opp = 1;
            } else {
                opp = 0;
            }

            if(link->getType() == "V") {                            // else download to opponent
                this->players[opp]->setDownloadedViruses(1 + this->players[opp]->getDownloadedViruses());
            } else {
                this->players[opp]->setDownloadedData(1 + this->players[opp]->getDownloadedData());
            }


        }


         //reveal link to other player here;

        // Remove the link from the current position
        board->getCell(currentRow, currentCol)->removeLink();
    }
    }

    return true;
}

int Game::checkWin() {
    if(this->players[1]->getDownloadedData() >= 4 || this->players[0]->getDownloadedViruses() >= 4 ) {           // 2 = player 2 wins
        return 2;
    } else if (this->players[0]->getDownloadedData() >= 4 || this->players[1]->getDownloadedViruses() >= 4 ) {    // 1 = player 1 wins
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
    if ('a' <= linkChar && linkChar <= 'h') {
        // player 1
        int linkIndex = linkChar - 'a';
        return getPlayer(0)->getLink(linkIndex);
    }
    else if ('A' <= linkChar && linkChar <= 'H') {
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



bool Game::processCommand(const string& input) {
    istringstream stream(input);
    string cmd;
    stream >> cmd;
     if (cmd == "move") {
        char linkChar;
        char direction;
        stream >> linkChar >> direction;
        Link *link = charToLink(linkChar);
        if (moveLink(link, direction)) {
            switchTurn();
            notifyObservers();
        }
        else {
            std::cout << "Move not valid";
        }
            
    }else if (cmd == "abilities") {
        for(const auto& player : players) {
            player->displayAbilities();
        }

    }else if (cmd == "ability") {
        int abilityID;
        stream >> abilityID;
        int row;
        int col;
        char linkChar;
        char nextChar;
        stream >> nextChar;
        if (nextChar <= '9' && nextChar >= '0') { // inputted a target cell
            row = nextChar - '0';
            stream >> col;
            Cell *cell = getBoard()->getCell(row, col);
            getPlayer(currentPlayerIndex)->useAbility(abilityID, *cell);
        }
        else if ((nextChar <= 'z' && nextChar >= 'a') || (nextChar <= 'Z' && nextChar >= 'A')) {     // inputted a target link
            linkChar = nextChar;
            Link *link = charToLink(linkChar); 
            getPlayer(currentPlayerIndex)->useAbility(abilityID, *link);
        }
        else {
            std::cout << "Ability cmd not correct";
        }
    }
    else if (cmd == "board") {
        notifyObservers();
    }
    else if (cmd == "sequence") {
        string filename;
        stream >> filename;
        extractFile(filename);
    }
    else if (cmd == "quit") {
        return false;
    }// add checwin 
    return true;
}

void Game::gameLoop() {
    string input;
    while(getline(cin, input)) {
        if (!processCommand(input)) {
            break;
        }
        int winStatus = checkWin();
        if (winStatus != 0) {
            cout << "Player " << winStatus << " wins !" << endl; 
        }
    }
}

void Game::extractFile(const string& filename) {
    ifstream file(filename);
    string cmd;
    while(getline(file, cmd)) {
        processCommand(cmd);
    }
}