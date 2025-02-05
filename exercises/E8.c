#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void print_numbers(int *array, int count){ // luodaan funktio jossa kaksi parametria, pointteri listaan ja listan pituus
  for(int i = 0; i < count; i++){ // tehdään listan pituuden pitkä looppi käyttäen parametrista saatua muuttujaa
    printf("%8d \n", array[i]); // printataan listan i alkio
  }
}


int main(void){ // pää ohjelma
  srand(time(0)); // tarvitaan aika, jotta random olisi enemmän random
  int random_numerot[15]; // luodaan 15 lukua sisältävä lista
  for(int i = 0; i < 15; i++){ // 15 kierrosta looppi
    random_numerot[i] = rand() % 100000; // täytetään lista random numeroilla 0-99999
  }
  int *pointer_to_array = random_numerot; // luodaan pointteri osoittamaan listaa
  print_numbers(pointer_to_array, 15); // kutsutaan muuttujaa

  return 0;
}
