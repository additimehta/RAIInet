#include "graphicalobserver.h"


GraphicalObserver::GraphicalObserver(Game *game){
    this->game = game;
    window = new Xwindow(500, 500);  
}


void GraphicalObserver::drawPlayerInfo(int playerIndex, int downloadedData, int downloadedViruses, int abilitiesCount, int x, int y) {
    window->drawString(x, y, "Player " + std::to_string(playerIndex + 1) + ":");
    window->drawString(x, y + 20, "Downloaded: " + std::to_string(downloadedData) + "D, " + std::to_string(downloadedViruses) + "V");
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

    drawPlayerInfo(0, downloadedData1, downloadedViruses1, abilitiesCount1, 10, 10);
    drawPlayerInfo(1, downloadedData2, downloadedViruses2, abilitiesCount2, 10, 50);
}

GraphicalObserver::~GraphicalObserver() {
    delete window;
}