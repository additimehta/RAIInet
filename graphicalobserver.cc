#include "graphicalobserver.h"



GraphicalObserver::GraphicalObserver(Game *game, Player *player): window {std::make_unique<Xwindow>(400, 750)}, game {game}, player {player} {game->attach(this);}


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
       if (i == 3) {
           window->drawString(xOff, yOff, linkInfo);
           yOff += 20;
           xOff = 10;
       } else {
           window->drawString(xOff, yOff, linkInfo + " ");
           xOff += 40;
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


       if (i == 3) {
           window->drawString(xOff, yOff, linkInfo);
           yOff += 20;
           xOff = 10;
       } else {
           window->drawString(xOff, yOff, linkInfo + " ");
           xOff += 30;
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
                Cell *cell = board->getCell(j, i);
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
                window->fillRectangle(i * 50, 120 + (j * 50), 50, 50, colour);
                window->drawString((i * 50) + 25, 120 + (j * 50) + 25, s);
            }
        }
}


void GraphicalObserver::notify() {
    window->fillRectangle(0, 0, 400, 750, Xwindow::White);
    Player* player1 = game->getPlayer(0);
    Player* player2 = game->getPlayer(1);
    drawPlayerInfo(player1, 20);
    drawBoard();
    drawOpponentInfo(player2, 570);
}

GraphicalObserver::~GraphicalObserver() {
    game->detach(this);
}
