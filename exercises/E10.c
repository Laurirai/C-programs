#include <stdio.h>
#include <string.h>

int main(void){
  char word[100]; // storing space for the string
  while (1){ // creating an infinite loop till the user types: stop
    printf("Please type out a word or 'stop' in order to stop:\n"); // asking the user for the string
    fgets(word, sizeof(word), stdin); // getting the user input
    word[strcspn(word, "\n")] = '\0'; // removing newline character

    int length = strlen(word); // storing the length of the string to a variable
    printf("The length of the word is: %d\n", length); // printing the length

    if (length == 0){ // if length = 0
      printf("The word is empty\n");
      continue; // starting the loop from top
    }
    if (strcmp(word, "stop") == 0) break; // if the string is: stop , we close the loop, and so forth the program


  }

  return 0;
}
