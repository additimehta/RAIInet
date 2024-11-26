#include "subject.h"
#include "observer.h"
#include <stdexcept>


void Subject::attach(Observer* o) {
  observers.emplace_back(o);
}

void Subject::detach(Observer* o) {
  for (size_t i = 0; i < observers.size(); ++i) {
    if (observers[i] == o) {
      delete observers[i];  
      observers.erase(observers.begin() + i);  
      return; 
    }
  }
}

void Subject::notifyObservers() {
  for (auto &obs : observers) {
    obs->notify();
  }
}

Subject::~Subject() {}