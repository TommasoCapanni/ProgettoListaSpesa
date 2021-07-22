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
            std::map<std::string, Articolo> chList = i->getArticleList();
            std::cout << "-" << i->getName() << std::endl;
            for (auto &j : i->getList()) {
                std::cout << "--" << j.first << " - " << std::to_string(j.second);
                auto artItr = chList.find(j.first);
                if (artItr->second.getCheck())
                    std::cout << " x";
                std::cout << std::endl;
            }
        }
    }

    void display(ShoppingList list) const {
        std::map<std::string, int> shList = list.getList();
        std::map<std::string, Articolo> chList = list.getArticleList();
        std::cout << "Lista " << list.getName() << std::endl;
        std::cout << "-" << user->getName() << std::endl;
        for (auto &i : shList) {
            std::cout << "--" << i.first << " - " << std::to_string(i.second);
            auto artItr = chList.find(i.first);
            if (artItr->second.getCheck())
                std::cout << " x";
            std::cout << std::endl;
        }
    }


private:
    User *user;
};

#endif //PROGETTOLISTASPESA_DISPLAY_H
