#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

typedef struct {
    char itemName[100];
    char itemDescription[100];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase *item);

void PrintItemCost(ItemToPurchase item);

void PrintItemDescription(ItemToPurchase item);

#endif