//
// Created by Tommaso Capanni on 12/07/2021.
//

#include "ShoppingList.h"

void ShoppingList::addItem(Articolo ar, int i) {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end()) {
        shopList[ar.getName()] += i;
    } else
        shopList.insert({ar.getName(), i});
    notify();
}

void ShoppingList::removeItem(Articolo ar) {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end()) {
        shopList[ar.getName()] -= 1;
        if (shopList[ar.getName()] == 0)
            shopList.erase(ar.getName());
        notify();
    }
}

bool ShoppingList::findItem(Articolo ar) {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end())
        return true;
    return false;

}

void ShoppingList::notify() {
    for (auto &i : obs) {
        i->update(*this);
    }
}