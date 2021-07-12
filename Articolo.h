//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_ARTICOLO_H
#define PROGETTOLISTASPESA_ARTICOLO_H

#include <string>

class Articolo {
public:
    Articolo(std::string name) : name(name) {};

    std::string getName() { return name; }

private:
    std::string name;
};

#endif //PROGETTOLISTASPESA_ARTICOLO_H
