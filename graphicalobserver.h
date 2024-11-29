#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "game.h"
#include "board.h"
#include "cell.h"
#include "window.h"
#include <iostream>
#include <vector>
#include <string>


class GraphicalObserver : public Observer {
    Xwindow* window;
    Game* game;
    Player *player;
    public:
    GraphicalObserver(Game *game, Player *player);
    ~GraphicalObserver();

    void drawPlayerInfo(Player *player, int yOff);
    void drawBoard();
    void drawOpponentInfo(Player *opponent, int yOff);
    //void drawBoard(const std::vector<std::vector<int>>& board);
    void notify() override;

};

#endif