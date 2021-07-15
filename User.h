//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_USER_H
#define PROGETTOLISTASPESA_USER_H

#include "ShoppingList.h"

class User {
public:
    User(std::string name) : name(name) {};

    void addList(ShoppingList *sl);

    std::vector<ShoppingList *> getLists() const { return shopLists; }

    void subscribe(Observer *o) {
        for (auto &i : shopLists) {
            i->attach(o);
        }
    }

    void unsubscribe(Observer *o) {
        for (auto &i : shopLists) {
            i->detach(o);
        }
    }

    std::string getName() const { return name; }

private:
    std::string name;
    std::vector<ShoppingList *> shopLists;
};


#endif //PROGETTOLISTASPESA_USER_H
