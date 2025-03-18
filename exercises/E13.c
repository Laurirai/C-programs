#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// in my testing file ive got numbers between 2-8
// with testing i realised my ide is running the program from the folder C-programs
// even though the e13 file is in directory exercises
// so if we'd like to open a file in that directory
// we could use something like this:
// snprintf(fullPath, sizeof(fullPath), "exercises/%s", filename);
// fp = fopen(fullPath, "r");

int main(void){
  char filename[100]; // initialize memory for filename
  FILE *fp; // creating a pointer to file
  int placeholder_number; // variable to hold integers read from the file

  // read somewhere that this is common practice for handling integers
  int smallest_number = INT_MAX; // initializing the variable to the largest integer
  int largest_number = INT_MIN; // initializing the variable to the smallest integer
  int counter = 0;

  printf("Enter a file name: ");
  scanf("%s",filename); // scanning the file name to the array created earlier

  // if file exists the "filename" is oppened for input from the first character in the file
  // if the file does not exist, fopen returns NULL
  fp = fopen(filename, "r");

  if(fp == NULL){
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // fscan returns 1 if succesfull
  // will loop till doesn't get a new number from the file
  while(fscanf(fp, "%d", &placeholder_number) == 1){
    counter++;

    if(placeholder_number < smallest_number){ // comparing the numbers
      smallest_number = placeholder_number;
    }
    if(placeholder_number > largest_number){
      largest_number = placeholder_number;
    }
  }

  if (counter > 0){
    printf("How many numbers read: %d\n",counter);
    printf("The smallest number is: %d\n",smallest_number);
    printf("The largest number is: %d\n",largest_number);
  }
  else{
    printf("There was no numbers in the file, but it was successfully opened.\n");
  }

  fclose(fp); // good practise to close the file after use :)

  return 0;
}
