#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl){ // creating the function

  int counter = 0; // creating a variable counter to count the changes
  int len = strlen(str); // getting the length of the string
  if (strlen(repl) < 2) { // just checking if the length is what it is supposed to b
    return 0;
  }
  char first_character = repl[0]; // getting the letter that we want to change
  char second_character = repl[1]; //getting the letter we want the aforementioned letter to change to

  for (int i = 0; i < len; i++) { // creating a loop to iterate through the string
    if (str[i] == first_character) { // if the strings char is the same as the letter
      str[i] = second_character; // changing it to the other letter
      counter++; // adding to the counter if change took place
    }
  }
  return counter; // returning the counter
}



int main(void){ // creating the main function/program
  char str[100]; // creating a list(array) for the characters
  char repl[3]; // 2 char + end of line (null terminator)
  printf("Enter a string: "); // asking for the string
  scanf("%99s", str); // setting to 99 char max to prevent a buffer overflow
  printf("Enter two characters: "); // asking for both letters
  scanf("%2s", repl); // setting it to two to prevent a buffer overflow

  int count = replace_char(str, repl); // calling the function and saving the result in the variable
  printf("How many changes: %d\n", count); // printing
  printf("New string: %s\n", str);
  return 0;
}
