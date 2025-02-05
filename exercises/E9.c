#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array,unsigned int what){ // luodaan funktio
  for (int index = 0; index < 20; index++) { // 20 kierrosta looppi
    if (array[index] == what) { // jos indexi sama kuin haluttu numero
      return index; // palautetaan indexi
    }
  }
  return -1; // jos numeroa ei löytynyt palautetaan -1
}


int main(void) { // Pää ohjelma

  srand(time(0)); // otetaan hetken aika, jotta random olisi enemmän random
  int my_array[20]; // luodaan lista jossa voi olla 20 numeroa
  for (int i = 0; i < 19; i++){ // 19 kierroksen looppi
    my_array[i] = (rand() % 20) + 1; // lisätään alkioihin random luku väliltä 1-20
  }
  my_array[19] = 0; // lisätään viimeiseen alkioon luku 0

  for (int i = 0; i < 20; i++) { // 20 kierroksen looppi
    printf("%d\n",my_array[i]); // printataan listan alkiot
  }

  while (1) { // while looppi
    int searched_number; // alusteaan muuttuja
    printf("What number would you like to search between 1-20? 0 to stop: "); // kysytään
    scanf("%d", &searched_number); // tallennetaan käyttäjän vastaus muuttujaan
    if (searched_number == 0){ // jos käyttäjän vastaus 0
      break; // suljetaan looppi
    }
    int results = find_first(my_array, searched_number); // kutsutaan muuttujaa ja tallennetaan tulos muuttujaan
    if (results == -1){ // jos tulos -1
      printf("Not found\n"); // tarkoitti sitä, ettei numeroa ollut ja printataan info
    } else { // muuten
      printf("%d\n", results); // printataan tulos muuttujasta (indexi listalta)
    }

  }
  return 0;
}