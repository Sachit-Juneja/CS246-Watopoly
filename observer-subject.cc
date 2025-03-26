#include "observer-subject.h"

void Subject::attachObservers(Observer *o){
    observers.emplace_back(o);
}

void Subject::detachOBservers(Observer *o){
    observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}

void Subject::notifyObservers(){
    for(auto* o: observers){
        o->notify();
    }
}
