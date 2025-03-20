#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100 // defining max'es
#define MAX_LENGHT_OF_LINE 81 // 80 + null

int main(void){
  char filename[100]; // initializing memory for the file name
  char strings [MAX_LINES][MAX_LENGHT_OF_LINE]; // initializing memory for the lines
  FILE * fp; // creating a pointer to file
  int counter = 0;

  printf("Enter filename: ");
  if (scanf("%s", filename) != 1){
    fprintf(stderr,"ERROR, FILENAME COULD NOT BE READ!\n");
  }

  fp = fopen(filename, "r"); // opening the file to read mode
  if (fp == NULL){
    fprintf(stderr,"ERROR, COULDN'T OPEN THE FILE %s!\n", filename);
    return -1;
  }

  // reading lines from the file until max is reached or there is nothing to read
  while (counter < MAX_LINES && fgets(strings[counter], MAX_LENGHT_OF_LINE, fp) != NULL){

    size_t len = strlen(strings[counter]); // removing the newline char, if there is one
    if (len > 0 && strings[counter][len - 1] == '\n'){
      strings[counter][len - 1] = '\0';
    }
    counter++;
  }
  fclose(fp);

  // chancing the small letters to uppercase letters
  for (int i = 0; i < counter; i++){
    for (int j = 0; strings[i][j] != '\0'; j++){
      strings[i][j] = toupper(strings[i][j]);
    }
  }

  fp = fopen(filename, "w"); // opening the file in write mode
  if (fp == NULL){
    fprintf(stderr,"ERROR, COULDN'T OPEN THE FILE %s!\n", filename);
    return -1;
  }

  // writing the new lines back to the file // this will replace the old ones
  for (int i = 0; i < counter; i++){
    fprintf(fp, "%s\n", strings[i]);
  }
  fclose(fp);

  return 0;
}
