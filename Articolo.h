//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_ARTICOLO_H
#define PROGETTOLISTASPESA_ARTICOLO_H


class Articolo {
public:
    Articolo(std::string name, std::string cat) : name(name), category(cat) {};


    std::string getName() const { return name; }

    std::string getCategory() const { return category; }


private:
    std::string name;
    std::string category;

};

#endif //PROGETTOLISTASPESA_ARTICOLO_H
