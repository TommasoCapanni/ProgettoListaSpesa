//
// Created by Tommaso Capanni on 14/07/2021.
//

#include <gtest/gtest.h>
#include "../User.h"

TEST(User, Constructor) {
    User us("Utente di prova");
    ASSERT_EQ("Utente di prova", us.getName());
}