#include "graphicalobserver.h"



GraphicalObserver::GraphicalObserver(Game *game, Player *player): game {game}, window {new Xwindow(500, 500)}, player {player} {}


void GraphicalObserver::drawPlayerInfo(Player *player, int yOff) {
   int xOff = 10;
   window->drawString(xOff, yOff, "Player " + std::to_string(player->getPlayerID() + 1) + ":");
   yOff += 20;
   window->drawString(xOff, yOff, "Downloaded: " + std::to_string(player->getDownloadedData()) + "D, " + std::to_string(player->getDownloadedViruses()) + "V");
   yOff += 20;


   window->drawString(xOff, yOff, "Abilities: " + std::to_string(player->getAbilitiesCount()));
   yOff += 20;


   char linkID = 'a';
   for (int i = 0; i < 8; ++i) {
       Link* link = player->getLink(i);
       std::string linkInfo = std::string(1, linkID) + ": " + link->getType() + std::to_string(link->getStrength());
       if (i == 4) {
           window->drawString(xOff, yOff, linkInfo);
           yOff += 20;
       } else {
           window->drawString(xOff, yOff, linkInfo + " ");
       }
       linkID++;
   }
}





void GraphicalObserver::drawOpponentInfo(Player *opponent, int yOff) {
int xOff = 10;
   window->drawString(xOff, yOff, "Opponent " + std::to_string(opponent->getPlayerID() + 1) + ":");
   yOff += 20;


   window->drawString(xOff, yOff, "Downloaded: " + std::to_string(opponent->getDownloadedData()) + "D, " + std::to_string(opponent->getDownloadedViruses()) + "V");
   yOff += 20;
  window->drawString(xOff, yOff, "Abilities: " + std::to_string(opponent->getAbilitiesCount()));
   yOff += 20;
  
   char linkID = 'A';
   for (int i = 0; i < 8; ++i) {
       Link* link = opponent->getLink(i);
       std::string linkInfo;
       if (link->getIsRevealed()) {
           linkInfo = std::string(1, linkID) + ": " + link->getType() + std::to_string(link->getStrength());
       } else {
           linkInfo = std::string(1, linkID) + ": ?";
       }


       if (i == 4) {
           window->drawString(xOff, yOff, linkInfo);
           yOff += 20;
       } else {
           window->drawString(xOff, yOff, linkInfo + " ");
       }
       linkID++;
   }
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
