//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_OBSERVER_H
#define ARTAUCTIONOOPEXAM_OBSERVER_H



class Observer {
public:
    virtual void update()=0;
    virtual ~Observer()=default;
};



#endif //ARTAUCTIONOOPEXAM_OBSERVER_H
