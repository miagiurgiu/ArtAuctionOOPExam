//
// Created by Maria on 27/06/2026.
//

#include "Subject.h"

void Subject::registerObserver(Observer *obs) {
    observers.push_back(obs);
}

void Subject::unregisterObserver(Observer *obs) {
    observers.erase(std::remove(observers.begin(),observers.end(),obs),observers.end());
}

void Subject::notify() {
    for (auto o:observers) {
        o->update();
    }
}
