//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_SHOPPINGLIST_H
#define PROGETTOLISTASPESA_SHOPPINGLIST_H


#include "Subject.h"
#include "Articolo.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(std::string name) : name(name) {};

    void addItem(const Articolo ar, int i = 1);

    void removeItem(const Articolo ar);

    bool findItem(const Articolo ar) const;

    std::string getName() const { return name; }

    std::map<std::string, int> getList() const { return shopList; }

    void attach(Observer *o) { obs.push_back(o); }

    void detach(Observer *o) { obs.remove(o); }

    void notify() const {
        for (auto &i : obs) {
            i->update((Subject *) this);
        }
    }

    void subscribe(Observer *o) {
        attach(o);
    }

private:
    std::string name;
    std::map<std::string, int> shopList;
    std::list<Observer *> obs;
};


#endif //PROGETTOLISTASPESA_SHOPPINGLIST_H
