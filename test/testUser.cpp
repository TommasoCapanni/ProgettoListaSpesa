//
// Created by Tommaso Capanni on 14/07/2021.
//

#include <gtest/gtest.h>
#include "../User.h"

TEST(User, Constructor) {
    User us("Utente di prova");
    ASSERT_EQ("Utente di prova", us.getName());
}

TEST(User, addList) {
    User us("Utente di prova");
    auto ptrsl1 = std::make_shared<ShoppingList>("Lista prova 1");

    us.addList(ptrsl1);

    ASSERT_EQ(1, us.getLists().size());
}