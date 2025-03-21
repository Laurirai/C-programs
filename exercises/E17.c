#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static const char RANDOM_CHARS[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*()-_=+[]{};:,.<>/?"
    "€§";

bool password_generator(char *pointer , int size, const char *starting_word){
  // calculating if we've got enough space
  int lenght_of_the_word = strlen(starting_word);
  int needed_size = (lenght_of_the_word * 2) + 1;

  //checking if weve got enough space
  if(needed_size + 1 > size){ // + null
    return false;
  }
  // i = 0 is also even so we start from there
  // the last char will also be even since we dont count for the null terminator
  for(int i = 0; i < needed_size; i++){
    if (i % 2 == 0){
      // Even index = new random
      int index_to_random = rand() % (sizeof(RANDOM_CHARS) - 1);
      pointer[i] = RANDOM_CHARS[index_to_random];
    } else { // odd index = letter from the users word
      pointer[i] = starting_word[i/2];
    }
  }
  pointer[needed_size] = '\0'; // adding null to the end
  return true;
}

int main(void){
  // seeding the random
  srand(time(NULL));
  char user_input[100];
  char password[201];

  while(true){
    printf("Enter the word you want modified ('stop' to end): \n");
    if(scanf("%s", user_input) != 1){
      fprintf(stderr, "ERROR READING THE INPUT\n");
      return 1;
    }
    if(strcmp(user_input, "stop") == 0){
      printf("Closing the program...\n");
      break;
    }

    if(!password_generator(password, sizeof(password), user_input)){
      printf("Couldn't generate password, Not enough space.\n");
    } else {
      printf("Generated password: %s\n", password);
    }
  }
  return 0;
}