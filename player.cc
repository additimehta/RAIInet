#include "player.h"

using namespace std;

Player::Player(int playerID, int downloadedData, int downloadedViruses, Board *board):
    playerID {playerID}, downloadedData {downloadedData}, downloadedViruses {downloadedViruses}, links {}, abilities {}, board{board} {}

void Player::addLink(unique_ptr<Link> link) {                      // take over ownership of link
    links.emplace_back(std::move(link));
}

void Player::addAbility(unique_ptr<Ability> ability) {             // take over ownership of ability
    abilities.emplace_back(std::move(ability));
}


void Player::addAbility(const string &a) {
    for(size_t i = 0; i < 5; i++) {
        if(a[i] == 'P') {
            addAbility(std::make_unique<Polarize>(this));
        }else if(a[i] == 'L') {
            addAbility(std::make_unique<Linkboost>(this));
        }else if(a[i] == 'F') {
            addAbility(std::make_unique<Firewall>(this));
        }else if(a[i] == 'D') {
            addAbility(std::make_unique<Download>(this));
        }else if(a[i] == 'Z') {
            addAbility(std::make_unique<Zigzag>(this));
        }else if(a[i] == 'S') {
            addAbility(std::make_unique<Scan>(this));
        }else if(a[i] == 'A') {
            addAbility(std::make_unique<Amplifier>(this));
        }else if(a[i] == 'W') {
            addAbility(std::make_unique<WarpShift>(this));
        }
    }
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

Board *Player::getBoard() const {
    return board;
}



vector<Link*> Player::getAllLinks() const {
    vector<Link*> result;
    for (const auto &link : links) { 
        result.push_back(link.get());
    }
    return result;
}

void Player::setDownloadedData(int i) {
    downloadedData = i;
}
void Player::setDownloadedViruses(int i) {
    downloadedViruses = i;
}


void Player::displayAbilities() const {
    cout << "Player " << playerID + 1 << " Abilities: " << endl;
    if (abilities.empty()) {
        cout << "No abilities assigned." << endl;
    } else {
        for (int i = 0; i < 5; ++i) {
            cout << i << ". " << abilities[i]->getName()
                << " " << (abilities[i]->hasBeenUsed() ? "Used" : "Unused") 
                << endl;
        }
    }
}
