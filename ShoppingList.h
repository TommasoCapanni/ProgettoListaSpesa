//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SHOPPINGLIST_H
#define PROGETTOLISTASPESA_SHOPPINGLIST_H

#include "Articolo.h"
#include "Subject.h"
#include <map>

class ShoppingList : public Subject {
public:
    explicit ShoppingList(std::string name) : name(name) {};

    ~ShoppingList() override {
        for (auto &i : obs) {
            delete i;
        }
    }

    void addItem(Articolo ar, int i = 1);

    void removeItem(Articolo ar);

    bool findItem(Articolo ar);

    std::string getName() const { return name; }

    std::map<std::string, int> getList() const { return shopList; }

    void notify() override;

    void operator=(const std::map<std::string, int> &sl) {
        this->shopList = sl;
    }

private:
    std::string name;
    std::map<std::string, int> shopList;
};


#endif //PROGETTOLISTASPESA_SHOPPINGLIST_H
