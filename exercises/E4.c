#include <stdio.h>


int read_integer(void) { // alustetaan funktio
    int number;
    printf("Enter positive numbers or negative to stop: "); // kysytään numeroa
    scanf("%d", &number); // scannataan numero muuttujaan
    return number; // palautetaan numero pää ohjelmaan
}

int main(void) { // alustetaan pää ohjelma
    int sum = 0;
    int count = 0;
    float average; // alustetaan muuttujia
    while (1) { // kysytään käyttäjältä funktion avulla loopissa
        int value = read_integer(); // kutsutaan funktiota ja asetetaan paluu arvo muuttujaan
        if (value < 0) { // tarkastellaan numeroa
            if (count == 0) {
                printf("You haven't entered a single positive number yet...\n");
            } // lisäys koodiin, jos ei ole yhtään positiivisia numeroita
            else { // printtaus
                average = (float)sum / count;
                printf("You've entered %d positive numbers. The average is: %.3f", count, average);

            }
            break; // suljetaan looppi
        }
        if (value > 0) { // jos postiviininen, kasvatetaan counttia ja lisätään numero summaan
            count++;
            sum += value;
        }
    }
    return 0;
}