#include "player.h"

using namespace std;

Player::Player(int playerID, int downloadedData, int downloadedViruses):
    playerID {playerID}, downloadedData {downloadedData}, downloadedViruses {downloadedViruses}, links {}, abilities {} {}

void Player::addLink(unique_ptr<Link> link) {                      // take over ownership of link
    abilities.emplace_back(link);
}

void Player::addAbility(unique_ptr<Ability> ability) {             // take over ownership of ability
    abilities.emplace_back(ability);
}

void Player::useAbility(int abilityID, Link &targetLink) {          // abilityID should be 0-indexed
    abilities.at(abilityID)->use(targetLink);
}

void Player::useAbility(int abilityID, Cell &targetCell) {          // abilityID should be 0-indexed
    abilities.at(abilityID)->use(targetCell);
}

int Player::getPlayerID() const {
    return playerID;
}

int Player::getDownloadedData() const {
    return downloadedData;
}

int Player::getDownloadedViruses() const {
    return downloadedViruses;
}

Link *Player::getLink(int LinkID) const {                          // LinkID should be 0-indexed
    return links.at(LinkID).get();
}

Ability *Player::getAbility(int AbilityID) const {                 // abilityID should be 0-indexed
    return abilities.at(AbilityID).get();
}

int Player::getAbilitiesCount() const {
    return abilities.size();
}
