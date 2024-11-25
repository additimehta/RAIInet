#include "textobserver.h"
#include "game.h"

using namespace std;

Textobserver(Game* game, playerID) : game(game), playerID(playerID);

void TextObserver::notify() override {
    Player *player = game->getPlayer(playerID);
    Player *opponenet = game->getPlayer(3 - playerID); // either 1 or 2
    auto board = subject->board;
    

    cout << "Player " << playerID << ":" << endl;
    cout << "Downloaded: "<< player->downloadedData << 
    "D" << player->downloadedViruses << "V " << endl;

    cout << "Abilities: " << player->abilities.size() << "\n";
    char linkID = 'a';
    int count = 0;

    for(auto &link : links) {
        cout << linkID << ": " << link.getType() << link.getStrenegth();
        if(cout == 4) {
            cout << endl;
        }else {
            cout << " ";
        }

        linkID++;
    }
    cout << endl;
    std::cout << "========" << std::endl;


    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++){
            Cell *cell = game->board

        }
    }
    
}