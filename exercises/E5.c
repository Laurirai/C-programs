#include <stdio.h>

int read_range(int low, int high) { // luodaan funktio
    int number;    // alustetaan muuttuja
    while (1) { // kysytään loopissa
        printf("Please enter a number between %d and %d: ", low, high); //Kysytään väliltä
        scanf("%d", &number); // tallennetaan vastaus muuttujaan
        if (number >= low && number <= high) { //tarkastellaan numeroa
            printf("A number was successfully read\n");
            printf("The number was in the specified range\n");
            break;
        }
        printf("The number was not in the specified range\n"); // jos ei ollut hyväksyttävä numero
        printf("Please try again\n");
    }
    return number; // palautetaan muuttuja
}
int main(void) { // Pää ohjelma
    int low = 1;
    int high = 6; //Kova koodataan arvot
    printf("Let's play!!\n");
    for (int i = 1; i <= 3; i++) { // kolmen kierroksen looppi
        printf("Roll a die and enter your result.\n");
        int my_number = read_range(low, high); // kutsutaan funktiota
        if (my_number == 6) { //Tarkastellaan muuttujaa
            printf("I got %d. It is a tie!\n", my_number);
        }
        else {
            printf("I got %d. I win!\n", my_number + 1); // Lisätään muuttujaan + 1 jotta kone voittaa
        }
    }
    printf("Better luck next time. Bye!\n"); // loppu viesti
    return 0;
}
