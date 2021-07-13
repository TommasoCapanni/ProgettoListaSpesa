//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SUBJECT_H
#define PROGETTOLISTASPESA_SUBJECT_H

#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <iostream>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = 0;

    virtual void attach(Observer *o) = 0;

    virtual void detach(Observer *o) = 0;

    virtual void notify() const = 0;

};

inline Subject::~Subject() {}

#endif //PROGETTOLISTASPESA_SUBJECT_H
