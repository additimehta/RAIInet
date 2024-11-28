#include <iostream>
#include "textobserver.h"
#include "game.h"
#include "board.h"

using namespace std;

TextObserver::TextObserver(Game* game, int playerID) : game(game), playerID(playerID) {game->attach(this);}


void TextObserver::notify() {
    Player *player = game->getPlayer(playerID);
    Player *opponent = game->getPlayer(1 - playerID); // either 0 or 1

    cout << "Player " << player->getPlayerID() + 1 << ":" << endl;
    cout << "Downloaded: "<< player->getDownloadedData()<< 
    "D" << player->getDownloadedViruses() << "V " << endl;

    cout << "Abilities: " << player->getAbilitiesCount() << endl;
    char linkID = 'a';
    vector<Link *> links;
    for (int i = 0; i < 8; ++i) {
        links.emplace_back(player->getLink(i));
    };

    for(size_t i = 0; i < links.size(); ++i) {
        cout << linkID << ": " << links[i]->getType() << links[i]->getStrength();
        if(i == 4) {
            cout << endl;
        }else {
            cout << " ";
        }

        linkID++;
    }
    cout << endl;
    cout << "========" << endl;
    
    const Board *board = game->getBoard();

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++){
            Cell *cell = board->getCell(row, col);
            if(cell->getIsServerPort()) {
                cout << "S";
            }else if(cell->getLink()) {
                cout << cell->getOwner();
            }else {
                cout << cell->underneathLetter;
            }
        }
        cout << endl;
    }

    cout << "========" << endl;

    // Opponent Output
    cout << "Player " << opponent->getPlayerID() + 1 << ":" << endl;
    cout << "Downloaded: "<< opponent->getDownloadedData()<< 
    "D" << opponent->getDownloadedViruses() << "V " << endl;
    cout << "Abilities: " << opponent->getAbilitiesCount() << endl;

    char opplinkID = 'A';

    vector<Link *> oppLinks;
    for (int i = 0; i < 8; ++i) {
        oppLinks.emplace_back(opponent->getLink(i));
    };

    for(size_t i = 0; i < oppLinks.size(); ++i) {

        if(oppLinks[i]->getIsRevealed()) {
            cout << opplinkID << ": " << oppLinks[i]->getType() << oppLinks[i]->getStrength();
        }else {
            cout << opplinkID << ": ?";
        }
        if(i == 4) {
            cout << endl;
        }else {
            cout << " ";
        }

        opplinkID++;
    }

    cout << endl;   
}

TextObserver::~TextObserver() {
    game->detach(this);
}