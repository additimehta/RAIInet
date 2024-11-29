#include "download.h"
#include "player.h"
#include "link.h"
#include <stdexcept>

Download::Download(Player *player) : Ability(player) {}



bool Download::use(Link &targetLink) {
    if(isUsed) {
        std::cout << "Download ability has already been used!" << std::endl;
        return false;
    }


    if(targetLink.getOwner() == player) {
        cout << "Please put the opponent's link  ";
        return false;
    }
    player->setDownloadedData(player->getDownloadedData() + 1);
    markUsed();
    return true;
}


bool Download::use(Cell &targetCell) {
    std::cout << "Download ability can only be used on Links!";
    return false;
}


std::string Download::getName() const {
    return "Download";
}
