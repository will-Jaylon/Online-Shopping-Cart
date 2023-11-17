#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "ItemToPurchase.h"

typedef struct ShoppingCart {
    char customerName[100];
    char currentDate[100];
    ItemToPurchase cartItems[10];
    int cartSize;
} ShoppingCart;

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);
ShoppingCart RemoveItem(char itemName[], ShoppingCart cart);
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart);
int GetNumItemsInCart(ShoppingCart cart);
int GetCostOfCart(ShoppingCart cart);
void PrintTotal(ShoppingCart cart);
void PrintDescriptions(ShoppingCart cart);

#endif