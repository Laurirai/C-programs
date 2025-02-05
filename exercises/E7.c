
#include <stdio.h>
#include <stdbool.h> // bool arvojen käsittelyyn


bool read_positive(int *value) { // luodaan funktio, parametriksi pointteri
  if (value == NULL) { // tarkistetaan, ettei pointteri ole tyhjä
    return false; // palautetaan epätosi
  }

  int itse_arvo = scanf("%d", value); // tallennetaan pointterin pointtaama arvo

  if (itse_arvo != 1) { // jos arvo ei ole numeroita
    while (getchar() != '\n'); // tyhjennetään ''bufferi'' väärän syötteen jälkeen
    return false; // palautetaan epätosi
  }

  if (*value > 0) { // tarkistetaan, onko annettu arvo positiivinen
    return true; // palautetaan tosi, jos positiivinen
  } else { // jos arvo ei ollut positiivinen
    return false; // palautetaan epätosi
  }
}

int main(void){
  int countteri = 0; // virhe laskuri

  while (1) {
    printf("Guess how much money I have! \n");
    printf("Enter a positive number: "); // kyssärit

    int number; // luodaan muuttuja syötteelle
    if (read_positive(&number)) { // tarkistetaan syöte funktiolla
      int tietokoneen_rahat = (number * 2) + 20; // lasketaan tietokoneen rahat
      printf("You didnt get it right. I have %d euros.\n", tietokoneen_rahat); // tulostetaan vastaus
    } else {
      countteri++; // kasvatetaan laskuria
      printf("Incorrect input\n"); // ilmoitetaan virheellisestä syötteestä
      if (countteri == 3) { // tarkistetaan, onko annettu kolme virheellistä syötettä
        printf("I give up! See you later!\n");
        break; // poistutaan loopista
      }
    }
  }
  return 0;
}