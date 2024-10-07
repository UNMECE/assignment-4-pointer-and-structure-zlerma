// Zaid Orozco-Lerma
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

// Here are all our functions
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;
    
    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    
    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
    
    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
    free(item_list); // Here we are freeing the array itself
}

double average_price(Item *item_list, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += item_list[i].price;
    }
    return size > 0 ? sum / size : 0;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.6f\n", item_list[i].price);
        printf("###############\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sku>\n", argv[0]);
        return 1;
    }

    Item *items = malloc(5 * sizeof(Item));
    if (!items) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    add_item(items, 5.0, "19282", "breakfast", "reese's cereal", 0);
    add_item(items, 3.95, "79862", "dairy", "milk", 1);
    add_item(items, 7.99, "26387", "fruit", "apple bag", 2);
    add_item(items, 1.29, "56231", "beverage", "coke can", 3);
    add_item(items, 2.50, "84567", "snack", "potato chips", 4);

    // We print all items, and then this is followed by the searched item
    print_items(items, 5);

    // Here we calculate and print the average price
    double avg = average_price(items, 5);
    printf("average price of items = %.6f\n", avg);

    // Here is our SKU search
    char *search_sku = argv[1];
    int ct = 0;
    while (ct < 5 && strcmp(items[ct].sku, search_sku) != 0) {
        ct++;
    }
    if (ct < 5) {
    	printf("\n\n============================================\n\n\n");
        printf("Searched Item found:\n");
        printf("###############\n");
        printf("item name = %s\n", items[ct].name);
        printf("item sku = %s\n", items[ct].sku);
        printf("item category = %s\n", items[ct].category);
        printf("item price = %.6f\n", items[ct].price);
        printf("###############\n");
    } else {
        printf("Item with SKU %s not found.\n", search_sku);
    }

    free_items(items, 5);
    return 0;
}
