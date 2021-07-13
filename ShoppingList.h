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

    void addItem(Articolo ar, int i = 1);

    void removeItem(Articolo ar);

    bool findItem(Articolo ar);

    std::string getName() const { return name; }

    std::map<std::string, int> getList() const { return shopList; }

    void notify() override;

    void operator=(const std::map<std::string, int> &sl) {
        this->shopList = sl;
    }

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
