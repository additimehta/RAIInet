#include "subject.h"
#include "observer.h"
#include <stdexcept>


void Subject::attach(Observer* o) {
  observers.emplace_back(o);
}

void Subject::detach(Observer* o) {
  for (size_t i = 0; i < observers.size(); ++i) {
    if (observers[i] == o) {
      observers.erase(observers.begin() + i);  
      return; 
    }
  }
}


Subject::~Subject() {}
