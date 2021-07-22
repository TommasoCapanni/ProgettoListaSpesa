//
// Created by Tommaso Capanni on 12/07/2021.
//

#include "ShoppingList.h"

void ShoppingList::addItem(const Articolo &ar, int i) {
    if (i <= 0)
        throw NegativeNumberException("Errore: il numero è negativo o nullo");
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end()) {
        shopList[ar.getName()] += i;
    } else {
        shopList.insert({ar.getName(), i});
        artList.insert({ar.getName(), ar});
    }
    notify();
}

void ShoppingList::removeItem(const Articolo &ar) {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end()) {
        shopList[ar.getName()] -= 1;
        if (shopList[ar.getName()] == 0) {
            shopList.erase(ar.getName());
            artList.erase(ar.getName());
        }
        notify();
    }
}

bool ShoppingList::findItem(const Articolo &ar) const {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end())
        return true;
    return false;
}

void ShoppingList::toggleCheckItem(const Articolo &ar) {
    auto itr = shopList.find(ar.getName());
    if (itr != shopList.end()) {
        auto art = artList.find(ar.getName());
        art->second.toggleCheck();
    }
}