#include "game.h"

Game::Game() : board(std::make_unique<Board>()), currentPlayerIndex(0), gameOver(false) {}

Game::~Game() {}

void Game::startGame() {
    board = std::make_unique<Board>();
    void initializeBoard();
    players.push_back(std::make_unique<Player>(1));
    players.push_back(std::make_unique<Player>(2));

    for (auto &player : players) {
        player->initializeLinks();
        player->initializeAbilities();
    }
    notifyObservers();

}
