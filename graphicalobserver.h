#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "game.h"
#include "board.h"
#include "window.h"
#include <iostream>
#include <vector>
#include <string>


class GraphicalObserver : public Observer {
    Xwindow* window;
    Game* game;
    public:
    GraphicalObserver(Game *game);
    ~GraphicalObserver();

    void drawPlayerInfo(int playerIndex, int downloadedData, int downloadedViruses, int abilitiesCount, int x, int y);
    //void drawBoard(const std::vector<std::vector<int>>& board);
    void notify() override;

};

#endif