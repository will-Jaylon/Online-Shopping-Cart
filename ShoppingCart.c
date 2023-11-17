#include <stdio.h>
#include <string.h>
#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
    if (cart.cartSize < 10) {
        cart.cartItems[cart.cartSize++] = item;
    } else {
        printf("Cannot add more items. Cart is full.\n");
    }
    return cart;
}

ShoppingCart RemoveItem(char itemName[], ShoppingCart cart) {
    int found = 0;
    for (int i = 0; i < cart.cartSize; i++) {
        if (strcmp(cart.cartItems[i].itemName, itemName) == 0) {
            found = 1;
            for (int j = i; j < cart.cartSize - 1; j++) {
                cart.cartItems[j] = cart.cartItems[j + 1];
            }
            cart.cartSize--;
            break;
        }
    }

    if (!found) {
        printf("Item not found in cart. Nothing removed.\n");
    }
    return cart;
}
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart) {
    for (int i = 0; i < cart.cartSize; i++) {
        if (strcmp(cart.cartItems[i].itemName, item.itemName) == 0) {
            cart.cartItems[i].itemQuantity = item.itemQuantity;
            printf("Item quantity modified in the cart.\n");
            return cart;
        }
        
    } printf("Item not found in cart. Nothing modified.\n");
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
    int total = 0;
    for (int i = 0; i < cart.cartSize; i++) {
        total += cart.cartItems[i].itemQuantity;
    }
    return total;
}
int GetCostOfCart(ShoppingCart cart) {
    int total = 0;
    for (int i = 0; i < cart.cartSize; i++) {
        total += cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity;
    }
    return total;
}
void PrintTotal(ShoppingCart cart) {
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n", GetNumItemsInCart(cart));

    for (int i = 0; i < cart.cartSize; i++) {
        PrintItemCost(cart.cartItems[i]);
    }

    if (cart.cartSize == 0) {
        printf("\nSHOPPING CART IS EMPTY");
    }
    int totalCost = GetCostOfCart(cart);
    printf("\n\nTotal: $%d\n", totalCost);

}

void PrintDescriptions(ShoppingCart cart) {
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("\nItem Descriptions\n");

    for (int i = 0; i < cart.cartSize; i++) {
        PrintItemDescription(cart.cartItems[i]);
    }
    if (cart.cartSize == 0) {
        printf("SHOPPING CART IS EMPTY\n");
    }
}