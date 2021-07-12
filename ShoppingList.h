//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SHOPPINGLIST_H
#define PROGETTOLISTASPESA_SHOPPINGLIST_H

#include "Articolo.h"
#include <map>

class ShoppingList {
public:
    ShoppingList(std::string name) : name(name) {};

    void addItem(Articolo ar, int i = 1);

    void removeItem(Articolo ar);

    bool findItem(Articolo ar);

private:
    std::string name;
    std::map<std::string, int> shopList;
};


#endif //PROGETTOLISTASPESA_SHOPPINGLIST_H
