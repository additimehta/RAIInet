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
    Observer *observer1 = new TextObserver {&game, 0};
    Observer *observer2 = new TextObserver {&game, 1};
    observers.emplace_back(observer1);
    observers.emplace_back(observer2);
    game.startGame();
    game.gameLoop();
    for (Observer* observer : observers) {
    delete observer;
  }

}
