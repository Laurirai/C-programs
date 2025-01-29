#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_d6(void) { // funktio 6puoliselle nopalle, arpoo luvun 1-6 ja palauttaa sen
    return (rand() % 6) + 1;
}
int roll_d10(void) { // saman kaltainen funktio kuin ylempänä, mutta kymmenpuoliselle nopalle.
    return (rand() % 10) + 1;
}
int main(void) {
    srand(time(NULL));
    // en täysin ymmärtänyt miksi, mutta random arvon luonti liittyi hetkelliseen aikaan ja tätä tarvitaan siihen
    //srand(time(NULL) ilmeisesti tarkastaa ajan, jotta random arvo olisi enemmän random..?
    while (1) { // looppi menun printtaukseen
        printf("Roll D6(1)\n");
        printf("Roll D10(2)\n");
        printf("Quit(3)\n");
        printf("Enter a number between 1-3 to choose: ");
        int choice;
        scanf("%d", &choice); // tallennetaan vastaus muuttujaan
        switch (choice) { // käsitellään vastaus switchissä, jokaiselle vastaukselle oma jatkonsa
            case 1: // jos vastaus == 1
                int my_roll = roll_d6(); // kutsutaan muuttujaa
            printf("You rolled %d\n", my_roll); // printtaus
            break; // poistutaan switchistä, mutta pysytään while loopissa
            case 2: // jos vastaus == 2
                int my_roll_d10 = roll_d10(); // kutsutaan muuttujaa
            printf("You rolled %d\n", my_roll_d10);
            break; // poistutaan switchistä, mutta pysytään while loopissa
            case 3: // jos vastaus == 3
                return 0; // suljetaan ohjelma
            default: // jos vastaus muuta kuin 1-3
                printf("Wrong number was pressed, please try again\n");
        }
    }
}
