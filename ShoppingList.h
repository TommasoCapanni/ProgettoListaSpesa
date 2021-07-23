//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SHOPPINGLIST_H
#define PROGETTOLISTASPESA_SHOPPINGLIST_H

#include <memory>
#include "Subject.h"
#include "Articolo.h"
#include "NegativeNumberException.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(std::string name) : name(name) {};

    void addItem(const Articolo &ar, int i = 1);

    void removeItem(const Articolo &ar);

    bool findItem(const Articolo &ar) const;

    void toggleCheckItem(const Articolo &ar);

    std::string getName() const { return name; }

    std::map<std::string, int> getList() const { return shopList; }

    std::map<std::string, Articolo> getArticleList() const { return artList; }

    int getListSize() const { return shopList.size(); }

    int getBoughtItemsNumber() const { return boughtItems; }

    void attach(Observer *o) { obs.push_back(o); }

    void detach(Observer *o) { obs.remove(o); }

    void notify() const {
        for (auto &i : obs) {
            i->update((Subject *) this);
        }
    }


private:
    std::string name;
    std::map<std::string, int> shopList;
    std::list<Observer *> obs;
    std::map<std::string, Articolo> artList;
    int boughtItems;
};


#endif //PROGETTOLISTASPESA_SHOPPINGLIST_H
