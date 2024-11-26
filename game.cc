#include "game.h"

Game::Game() : board(std::make_unique<Board>()), currentPlayerIndex(0), gameOver(false) {}

Game::~Game() {}

void Game::startGame() {
    board = std::make_unique<Board>();
    board->initializeBoard();
    players.push_back(std::make_unique<Player>(1));
    players.push_back(std::make_unique<Player>(2));
    players[0]->initializeLinks(board.get(),

    currentPlayerIndex = 0;
    notifyObservers();

}
