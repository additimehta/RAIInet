#include "textobserver.h"
#include "game.h"

using namespace std;

Textobserver(Game* game, playerID) : game(game), playerID(playerID);

void TextObserver::notify() override {
    Player *player = game->getPlayer(playerID);
    Player *opponenet = game->getPlayer(3 - playerID); // either 1 or 2

    

    cout << "Player " << playerID << ":" << endl;
    cout << "Downloaded: "<< player->getDownloadedData()<< 
    "D" << player->getDownloadedViruses() << "V " << endl;

    cout << "Abilities: " << player->getAbilitiesCount() << endl;
    char linkID = 'a';
    const auto& links = player->getLinks();

    for(size_t i = 0; links.size(); ++i) {
        cout << linkID << ": " << links[i]->getType() << links[i]->getStrenght();
        if(i == 4) {
            cout << endl;
        }else {
            cout << " ";
        }

        linkID++;
    }
    cout << endl;
    cout << "========" << endl;
    
    const Board& board = game->getBoard();

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++){
            Cell *cell = board.getCell(row, col);
            if(cell->isServerPort) {
                cout << "SS";
            }else if(cell->link) {
                cout << cell->owner;
            }else {
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << "========" << endl;

    // Opponent Output
    cout << "Player " << 3 - playerID << ":" << endl;
    cout << "Downloaded: "<< opponenet->getDownloadedData()<< 
    "D" << opponenet->getDownloadedViruses() << "V " << endl;
    cout << "Abilities: " << opponenet->getAbilitiesCount() << endl;

    linkID = 'A';
    count = 0;
    const auto& oppLinks = opponent->getLinks();
    for(size_t i = 0; oppLinks.size(); ++i) {

        if(links[i].getisRevealed()) {
            cout << linkID << ": " << oppLinks[i]->getType() << oppLinks[i]->getStrenght();
        }else {
            cout << linkID << ": ?";
        }
        if(i == 4) {
            cout << endl;
        }else {
            cout << " ";
        }

        linkID++;
    }

    cout << endl;


    
}