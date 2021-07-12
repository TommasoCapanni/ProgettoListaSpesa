//
// Created by Tommaso Capanni on 12/07/2021.
//

#ifndef PROGETTOLISTASPESA_DISPLAY_H
#define PROGETTOLISTASPESA_DISPLAY_H

#include "ShoppingList.h"

class Display : public Observer {
public:
    Display(User us) : user(us), shopList(us.getLists()) {};

    void display() {
        std::cout << "Liste: " << std::endl;
        for (auto &i : shopList) {
            std::cout << "Lista " << i.getName() << std::endl;
            for (auto &j : i.getList()) {
                std::cout << j.first << " : " << j.second << std::endl;
            }
        }
    }

    void update(const ShoppingList &sl) override {
        for (auto &i : shopList) {
            if (i.getName() == sl.getName()) {
                i = sl.getList();
            }
        }
    }

private:
    User user;
    std::vector<ShoppingList> shopList;
};

#endif //PROGETTOLISTASPESA_DISPLAY_H
