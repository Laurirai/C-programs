#include <stdio.h>



#define ITEMS_MENU 40 // defining max items

typedef struct menu_item_ { // creating a struct for the items
  char name[50];
  double price;
} menu_item;

int main(void){
  char filename[100];
  FILE *fp;
  menu_item items[ITEMS_MENU]; // creating a array of structs
  int counter = 0;

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
  fclose(fp);
  // %4.2f is for : 4 width from the previous print, 2 is for how many decimals
  for (int i = 0; i < counter; i++){
    printf("%s %4.2f\n", items[i].name, items[i].price);
  }

  return 0;
}
