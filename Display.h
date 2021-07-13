//
// Created by Tommaso Capanni on 13/07/2021.
//

#ifndef PROGETTOLISTASPESA_DISPLAY_H
#define PROGETTOLISTASPESA_DISPLAY_H

#include "ShoppingList.h"

class Display : public Observer {
public:
    Display(User *u) : user(u) {
        u->subscribe(this);
        for (auto &i : u->getLists()) {
            lists.push_back(*i);
        }
    };

    ~Display() {
        user->unsubscribe((Observer *) this);
        delete user;
    }

    void update(Subject *shopList) {
        ShoppingList *ptr = dynamic_cast<ShoppingList *>(shopList);
        for (auto &i : lists) {
            if (i.getName() == ptr->getName()) {
                i = *ptr;
            }
        }
    }

    void display() {
        std::cout << "Liste utente: " << user->getName() << std::endl;
        for (auto &i : lists) {
            std::cout << "-" << i.getName() << std::endl;
            for (auto &j : i.getList()) {
                std::cout << "--" << j.first << " - " << std::to_string(j.second) << std::endl;
            }
        }
    }

private:
    User *user;
    std::vector<ShoppingList> lists;
};

#endif //PROGETTOLISTASPESA_DISPLAY_H
