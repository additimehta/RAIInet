#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "game.h"
#include <iostream>

class TextObserver : public Observer {
    Game* game;
    std::vector<std::vector<char>> gameBoard;
    int playerID;

public:
    TextObserver(Game* game, int playerID);
    ~TextObserver() override = default;
    void notify() override;
};

#endif