//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_SUBJECT_H
#define ARTAUCTIONOOPEXAM_SUBJECT_H
#include "Observer.h"
#include <vector>

class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};



#endif //ARTAUCTIONOOPEXAM_SUBJECT_H
