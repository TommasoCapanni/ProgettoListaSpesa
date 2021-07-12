//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_OBSERVER_H
#define PROGETTOLISTASPESA_OBSERVER_H

class Subject;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(Subject &) = 0;
};


#endif //PROGETTOLISTASPESA_OBSERVER_H
