#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ability.h"
#include "board.h"
#include "cell.h"
#include "link.h"
#include "observer.h"
#include "player.h"
#include "subject.h"
#include "textobserver.h"
#include "game.h"


int main() {
    std::string command;
    std::vector<Observer*> observers;
    Game game;
    game.startGame();
    game.gameLoop();
    for (Observer* observer : observers) {
    delete observer;
  }

}
