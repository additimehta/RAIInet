#include "download.h"
#include "player.h"
#include "link.h"
#include <stdexcept>

Download::Download(Player *player) : Ability(player) {}



bool Download::use(Link &targetLink) {
    if(targetLink.getOwner() == player) {
        cout << "invalid link";
        return false;
    }
    player->setDownloadedData(player->getDownloadedData() + 1);
    return true;
}

std::string Download::getName() const {
    return "Download";
}
