#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer-observer.h"

class Subject {

    std::vector<Observer*> observers;

    public:
        virtual void notifyObservers() = 0;
        virtual void attachObservers() = 0;
        virtual void detachOBservers() = 0;
};

#endif

