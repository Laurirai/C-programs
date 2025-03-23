#include <string.h>
#include <stdio.h>
#include <stdlib.h>



#define ITEMS_MENU 40 // defining max items

typedef struct menu_item_ { // creating a struct for the items
    char name[50];
    double price;
} menu_item;

// sorting alphabetically
int sort_by_name(const void *a, const void *b){
  const menu_item *item_a = a;
  const menu_item *item_b = b;
  return strcmp(item_a->name, item_b->name);
}

// sorting from cheapest to the most expensive
int sort_by_price(const void *a, const void *b){
  const menu_item *item_a = a;
  const menu_item *item_b = b;
  if (item_a->price > item_b->price){
    return 1;
  }
  if (item_a->price < item_b->price){
    return -1;
  }
  return 0;
}

int main(void){
    char filename[100];
    FILE *fp;
    menu_item items[ITEMS_MENU]; // creating a array of structs
    int counter = 0;
    int sorting_choice;

    printf("Enter the name of the file you want to read: ");
    if (scanf("%s", filename) != 1){
        fprintf(stderr,"ERROR, FILENAME COULD NOT BE READ!\n");
    }

    fp = fopen(filename, "r"); // opening the file to read mode
    if (fp == NULL){
        fprintf(stderr,"ERROR, COULDN'T OPEN THE FILE %s!\n", filename);
        return -1;
    }

    // looping until we hit the max number of items, or we dont have anything to parse anymore
    //%49[^;] reading up to 49 char or until ;, ;= skip the ¨;¨ and add a space
    while (counter < ITEMS_MENU && fscanf(fp, "%49[^;]; %lf", items[counter].name, &items[counter].price) == 2)
    {
        counter++;
    }

    printf("How would you like to sort your menu?\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    printf("Enter your choice: ");
    if (scanf("%d", &sorting_choice) != 1){
      fprintf(stderr, "Couldnt read the input.\n");
      return -1;
    }
    if (sorting_choice == 1){
      qsort(items, counter, sizeof(menu_item), sort_by_name);
    }
    else if (sorting_choice == 2){
      qsort(items, counter, sizeof(menu_item), sort_by_price);
    }
    else{
      fprintf(stderr,"ERROR, WRONG INPUT!\n");
      return -1;
    }


    // %4.2f is for : 4 width from the previous print, 2 is for how many decimals
    for (int i = 0; i < counter; i++){
        printf("%s %4.2f\n", items[i].name, items[i].price);
    }

    return 0;
}
