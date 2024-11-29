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
    int boardWidth, boardHeight;
    public:
    GraphicalObserver(int width, int height);
    ~GraphicalObserver();

    void drawPlayerInfo(int playerIndex, int downloadedData, int downloadedViruses, int abilitiesCount, const std::vector<std::string>& abilities);
    void drawBoard(const std::vector<std::vector<int>>& board);
    void notify() override;

};

#endif