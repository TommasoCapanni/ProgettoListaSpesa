//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_ARTICOLO_H
#define PROGETTOLISTASPESA_ARTICOLO_H


class Articolo {
public:
    Articolo(std::string name, std::string cat) : name(name), category(cat) { hasBeenTaken = false; };


    std::string getName() const { return name; }

    std::string getCategory() const { return category; }

    bool getCheck() const { return hasBeenTaken; }

    void toggleCheck() {
        hasBeenTaken = !hasBeenTaken;
    }


private:
    std::string name;
    std::string category;
    bool hasBeenTaken;

};

#endif //PROGETTOLISTASPESA_ARTICOLO_H
