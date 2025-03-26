#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <algorithm>
#include "observer-observer.h"
using namespace std;
class Subject {

    vector<Observer*> observers;

    public:
        void notifyObservers();
        void attachObservers(Observer *o);
        void detachOBservers(Observer *o);
};

#endif

