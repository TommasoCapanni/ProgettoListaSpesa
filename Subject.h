//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SUBJECT_H
#define PROGETTOLISTASPESA_SUBJECT_H

#include <vector>
#include <algorithm>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = 0;

    void attach(Observer &o) { obs.push_back(&o); }

    void detach(Observer &o) {
        auto itr = std::find(begin(obs), end(obs), &o);
        if (itr != obs.end()) {
            obs.erase(itr);
        }
    }

    virtual void notify() = 0;

protected:
    std::vector<Observer *> obs;
};

inline Subject::~Subject() {}

#endif //PROGETTOLISTASPESA_SUBJECT_H
