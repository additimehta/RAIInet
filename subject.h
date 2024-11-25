#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer;
using namespace std;

class Subject {
    vector<Observer*> observers;
    public: 
    void attach( Observer* o );
    void detach( Observer* o );
    void notifyObservers();
    virtual ~Subject() = 0;
};

#endif