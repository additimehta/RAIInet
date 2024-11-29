#include "download.h"
#include "player.h"
#include "link.h"
#include <stdexcept>

Download::Download(Player *player) : Ability(player) {}



bool Download::use(Link &targetLink) {
    if(isUsed || targetLink.getOwner() == player) {
        return false;
    }
    player->setDownloadedData(player->getDownloadedData() + 1);
    markUsed();
    return true;
}


bool Download::use(Cell &targetCell) {
    return false;
}


std::string Download::getName() const {
    return "Download";
}
