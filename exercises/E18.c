#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  srand(time(NULL)); // seeding time
  int shift;

  while(1){
    printf("Please enter a number between 0 and 15, or negative to exit: ");
    scanf("%d", &shift);

    if(shift < 0){ // if negative
      printf("Exiting...\n");
      break; // exit
    }

    if(shift > 15){ // if over 15
      printf("Incorrect number\n");
      continue;
    }

    unsigned int random_number = rand(); // creating the random
    printf("Random number in hexadecimals: 0x%X\n", random_number); // printing the rand in hex
    // number >> shift means logical right shift the bits of number by shift amounth
    unsigned int shifted_number = random_number >> shift;
    // to keep only bits between 0-5, 6 total
    // The mask 0x3F = binary 0011 1111 keeps us only the lowest 6 bits of the number
    shifted_number &= 0x3F;
    // printing the hex with atleast two digits
    printf("Shifted number in hexadecimals: 0x%02X\n", shifted_number);
  }


  return 0;
}