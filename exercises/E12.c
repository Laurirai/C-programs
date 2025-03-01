#include <stdio.h> // input output handling and buffer mechanisms
#include <string.h> // for the function strstr()

int count_words(const char *str, const char *word){ // creating a function
  int count = 0; // creating a variable for counting
  const char *found = strstr(str, word);
  // using the strstr function
  // note: the function returns const char * so our pointer will also be that to avoid warnings
  while (found){ // loop to check how many matches
    count++; // in case of a match, adding to count variable
    found = strstr(found + 1, word); // "hopping" on to the next word
  }
  return count; // returning the count variable
}

int main(void){ // creating the main prog/func
  char str[100], word[100]; // creating space for the string and the word

  while(1){ // loop to handle questioning
    printf("Enter a string:\n"); // asking the user for a string
    fgets(str, sizeof(str), stdin); // using fgets func to save the answer, bcs fgets can get the whole sentence
    str[strcspn(str, "\n")] = '\0'; // deleting the end of line marker
    printf("Enter a word: (write stop, in order to stop)\n"); // asking for the word
    scanf("%99s", word); // using scanf func to save the word
    getchar(); // deleting the end of line marker

    int counted_words = count_words(str, word); // calling the function and saving the returning value
    printf("Number of words: %d\n", counted_words); // printing the answer
    if (strcmp(word, "stop") == 0) break; // if word is 'stop' we hop on out of the program and that will also close it.
  }
  return 0;
}
