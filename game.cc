#include "game.h"

using namespace std;

Board *Game::getBoard() const {
    return board.get();
}

Player *Game::getPlayer(const int playerID) const {   // playerID must be 0-indexed
    return players.at(playerID).get();
}

int Game::getPlayerCount() const {
    return players.size();
}

int Game::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

void Game::addPlayer(std::unique_ptr<Player> player) {
    int current_size = getPlayerCount();
    players.emplace_back(player);
}

void Game::switchTurn() {       // need to add funcitonality to only iterate over "alive" players
    currentPlayerIndex++;
    if (currentPlayerIndex >= getPlayerCount()) {
        currentPlayerIndex = 0;
    }
}

