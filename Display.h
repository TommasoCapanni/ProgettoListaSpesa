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
    }

    ~Display() {
        user->unsubscribe((Observer *) this);
    }

    void update(Subject *shopList) {
        ShoppingList *ptr = dynamic_cast<ShoppingList *>(shopList);
        display(*ptr);
    }


    void display() const {
        std::cout << "Liste utente: " << user->getName() << std::endl;
        for (auto &i : user->getLists()) {
            std::vector<std::string> temp = i->getChecks();
            std::cout << "-" << i->getName() << std::endl;
            for (auto &j : i->getList()) {
                std::cout << "--" << j.first << " - " << std::to_string(j.second);
                for (auto &k : temp) {
                    if (k == j.first) {
                        std::cout << " x";
                        break;
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    void display(ShoppingList list) const {
        std::map<std::string, int> temp = list.getList();
        std::cout << "Lista " << list.getName() << std::endl;
        std::cout << "-" << user->getName() << std::endl;
        for (auto &i : temp) {
            std::cout << "--" << i.first << " - " << std::to_string(i.second) << std::endl;
        }
    }


private:
    User *user;
};

#endif //PROGETTOLISTASPESA_DISPLAY_H
