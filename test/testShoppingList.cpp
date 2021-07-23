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

TEST(ShoppingList, getListSize) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova 1", "Categoria 1");
    Articolo ar2("Articolo di prova 2", "Categoria 1");
    Articolo ar3("Articolo di prova 3", "Categoria 1");

    sl1.addItem(ar1);

    ASSERT_EQ(1, sl1.getListSize());

    sl1.toggleCheckItem(ar1);
    sl1.addItem(ar2);
    sl1.addItem(ar1);

    ASSERT_EQ(2, sl1.getListSize());

    sl1.toggleCheckItem(ar1);

    ASSERT_EQ(2, sl1.getListSize());

    sl1.removeItem(ar1);

    ASSERT_EQ(2, sl1.getListSize());

    sl1.addItem(ar3);
    sl1.removeItem(ar1);

    ASSERT_EQ(2, sl1.getListSize());

    sl1.removeItem(ar2);
    sl1.removeItem(ar3);
    ASSERT_EQ(0, sl1.getListSize());
}

TEST(ShoppingList, getBoughtItemsNumber) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova 1", "Categoria 1");
    Articolo ar2("Articolo di prova 2", "Categoria 1");

    sl1.addItem(ar1, 3);
    sl1.addItem(ar2);

    ASSERT_EQ(0, sl1.getBoughtItemsNumber());

    sl1.toggleCheckItem(ar1);

    ASSERT_EQ(3, sl1.getBoughtItemsNumber());

    sl1.toggleCheckItem(ar2);

    ASSERT_EQ(4, sl1.getBoughtItemsNumber());

    sl1.removeItem(ar1);

    ASSERT_EQ(3, sl1.getBoughtItemsNumber());

    sl1.toggleCheckItem(ar2);

    ASSERT_EQ(2, sl1.getBoughtItemsNumber());

    sl1.removeItem(ar2);

    ASSERT_EQ(2, sl1.getBoughtItemsNumber());
}

TEST(ShoppingList, getItemsToBuyNumber) {
    ShoppingList sl1("Lista prova");
    Articolo ar1("Articolo di prova 1", "Categoria 1");
    Articolo ar2("Articolo di prova 2", "Categoria 1");

    sl1.addItem(ar1);
    sl1.addItem(ar2);

    ASSERT_EQ(2, sl1.getItemsToBuyNumber());

    sl1.addItem(ar1, 3);

    ASSERT_EQ(5, sl1.getItemsToBuyNumber());

    sl1.removeItem(ar1);

    ASSERT_EQ(4, sl1.getItemsToBuyNumber());

    sl1.removeItem(ar2);

    ASSERT_EQ(3, sl1.getItemsToBuyNumber());
}