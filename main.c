#include <stdio.h>
#include <string.h>
#include "ShoppingCart.h"
void PrintMenu(ShoppingCart cart);

int main() {
    char customerName[100];
    char currentDate[100];
    char customerChoice;

    printf("Enter Customer's Name:\n");
    fgets(customerName, sizeof(customerName), stdin);
    strtok(customerName, "\n");

    printf("Enter Today's Date:\n");
    fgets(currentDate, sizeof(currentDate), stdin);
    strtok(currentDate, "\n");

    printf("\nCustomer Name: %s\n", customerName);
    printf("Today's Date: %s\n", currentDate);

    ShoppingCart cart;
    strcpy(cart.customerName, customerName);
    strcpy(cart.currentDate, currentDate);
    cart.cartSize = 0;

    PrintMenu(cart);
    do {
        printf("Choose an option:\n");
        scanf(" %c", &customerChoice);
        while (getchar() != '\n' && getchar() != EOF);

        if (customerChoice == 'a') {
            ItemToPurchase newItem;
            MakeItemBlank(&newItem);
            printf("\nADD ITEM TO CART\n");
            printf("Enter item name:\n");
            fgets(newItem.itemName, sizeof(newItem.itemName), stdin);
            strtok(newItem.itemName, "\n");

            printf("Enter the item description:\n");
            fgets(newItem.itemDescription, sizeof(newItem.itemDescription), stdin);
            strtok(newItem.itemDescription, "\n");

            printf("Enter the item price:\n");
            scanf("%d", &newItem.itemPrice);

            printf("Enter the item quantity:\n");
            scanf("%d", &newItem.itemQuantity);

            cart = AddItem(newItem, cart);
        }
        else if (customerChoice == 'r') {
            char itemNameToRemove[100];

            printf("REMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            fgets(itemNameToRemove, sizeof(itemNameToRemove), stdin);
            strtok(itemNameToRemove, "\n");

            cart = RemoveItem(itemNameToRemove, cart);
            PrintMenu(cart);
        }
        else if (customerChoice == 'c') {
            char itemToModify[100];
            int newQuant;

            printf("CHANGE ITEM QUANTITY\n");
            printf("Enter the item name:\n");
            fgets(itemToModify, sizeof(itemToModify), stdin);
            strtok(itemToModify, "\n");

            printf("Enter the new quantity:\n");
            scanf("%d", &newQuant);
            while (getchar() != '\n' && getchar() != EOF);

            ItemToPurchase itemModified;
            strcpy(itemModified.itemName, itemToModify);
            itemModified.itemQuantity = newQuant;

            cart = ModifyItem(itemModified, cart);
            PrintMenu(cart);
        }
        else if (customerChoice == 'i') {
            printf("OUTPUT ITEMS' DESCRIPTIONS\n");
            PrintDescriptions(cart);
            PrintMenu(cart);
        }
        else if (customerChoice == 'o') {
            printf("OUTPUT SHOPPING CART\n");
            PrintTotal(cart);
            PrintMenu(cart);
        }
    } while (customerChoice != 'q');
}


void PrintMenu(ShoppingCart cart) {
    printf("\nMENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n\n");
}
