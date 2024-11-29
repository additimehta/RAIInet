#include "graphicalobserver.h"



GraphicalObserver::GraphicalObserver(Game *game, Player *player): game {game}, window {new Xwindow(500, 500)}, player {player} {}


void GraphicalObserver::drawPlayerInfo(int playerIndex, int downloadedData, int downloadedViruses, int abilitiesCount, int x, int y) {
    window->drawString(x, y, "Player " + std::to_string(playerIndex + 1) + ":");
    window->drawString(x, y + 20, "Downloaded: " + std::to_string(downloadedData) + "D, " + std::to_string(downloadedViruses) + "V");
}

 void GraphicalObserver::drawBoard() {
    Board *board = game->getBoard();
    char letter;
    int colour = Xwindow::White;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                Cell *cell = board->getCell(i, j);
                if (cell->getIsServerPort()) {
                    colour = Xwindow::Blue;
                    letter = 'S';
                } 
                else if (cell->getLink() == nullptr) {   // no link on cell
                    colour = Xwindow::White;
                    letter = cell->underneathLetter;
                } 
                else if (cell->getLink()->getOwner() == player) { // player's own link
                    if (cell->getLink()->getType() == "V") colour = Xwindow::Red;
                    else colour = Xwindow::Green;
                    letter = cell->getOwner();
                }
                else if (cell->getLink()->getIsRevealed() == true) { // opponents revealed link
                    if (cell->getLink()->getType() == "V") colour = Xwindow::Red;
                    else colour = Xwindow::Green;
                    letter = cell->getOwner();
                }
                else {
                    colour = Xwindow::Black;
                }
                std::string s = string(1, letter);
                window->fillRectangle(40 + (i * 50), 40 + (j * 50), 50, 50, colour);
                window->drawString(40 + (i * 25), 40 + (j * 25), s);
            }
        }
}


void GraphicalObserver::notify() {
    Player* player1 = game->getPlayer(0);
    Player* player2 = game->getPlayer(1);
    int downloadedData1 = player1->getDownloadedData();
    int downloadedViruses1 = player1->getDownloadedViruses();
    int abilitiesCount1 = player1->getAbilitiesCount();
    

    int downloadedData2 = player2->getDownloadedData();
    int downloadedViruses2 = player2->getDownloadedViruses();
    int abilitiesCount2 = player2->getAbilitiesCount();

    drawBoard();
    drawPlayerInfo(0, downloadedData1, downloadedViruses1, abilitiesCount1, 10, 10);
    drawPlayerInfo(1, downloadedData2, downloadedViruses2, abilitiesCount2, 10, 50);
}

GraphicalObserver::~GraphicalObserver() {
    delete window;
}