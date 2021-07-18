//
// Created by Tommaso Capanni on 12/07/2021.
//

#include "User.h"

void User::addList(std::shared_ptr<ShoppingList> sl) {
    shopLists.push_back(sl);
}