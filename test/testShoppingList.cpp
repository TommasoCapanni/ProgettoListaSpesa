//
// Created by Tommaso Capanni on 12/07/2021.
//

#include <gtest/gtest.h>
#include "../ShoppingList.h"


TEST(ShoppingList, Constructor) {
    ShoppingList sl1("Lista prova 1");
    ASSERT_EQ("Lista prova 1", sl1.getName());
}

TEST(ShoppingList, FindItem) {
    ShoppingList sl1("Lista prova 1");
    Articolo ar1("Articolo nella lista");
    Articolo ar2("Aricolo non nella lista");
    sl1.addItem(ar1, 1);
    ASSERT_EQ(true, sl1.findItem(ar1));
    ASSERT_EQ(false, sl1.findItem(ar2));
}

TEST(ShoppingList, removeItem) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova");
    sl1.addItem(ar1);
    sl1.removeItem(ar1);
    ASSERT_EQ(false, sl1.findItem(ar1));
}

TEST(ShoppingList, getName) {
    ShoppingList sl1("Lista Prova 1");
    ASSERT_EQ("Lista Prova 1", sl1.getName());
}
