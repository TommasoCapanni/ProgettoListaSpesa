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
    Articolo ar1("Articolo nella lista", "Categoria 1");
    Articolo ar2("Aricolo non nella lista", "Categoria 1");
    sl1.addItem(ar1, 1);
    ASSERT_EQ(true, sl1.findItem(ar1));
    ASSERT_EQ(false, sl1.findItem(ar2));
}

TEST(ShoppingList, removeItem) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova", "Categoria 1");
    sl1.addItem(ar1);
    sl1.removeItem(ar1);
    sl1.removeItem(ar1);
    ASSERT_EQ(false, sl1.findItem(ar1));
}

TEST(ShoppingList, NegativeNumberException) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova", "Categoria 1");
    ASSERT_THROW(sl1.addItem(ar1, -1), NegativeNumberException);
}
