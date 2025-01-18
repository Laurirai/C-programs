#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    float bussi_lippu;
    float taxi_lippu;
    float varat;
    int valinta;


    printf("Paljonko bussilipulla on hintaa? : ");
    scanf("%f", &bussi_lippu);
    printf("Paljonko taxi maksaa? : ");
    scanf("%f", &taxi_lippu);
    printf("Paljonko sinulla on rahaa? : ");
    scanf("%f", &varat);

    if (bussi_lippu > varat && taxi_lippu > varat) {
        printf("Joudut valitettavasti tallustamaan loppumatkan...\n");
        exit(0);
    }

    while (varat >= taxi_lippu or varat >= bussi_lippu) {
        printf("Haluatko taksin vai bussin?\n");
        printf("(1) : Taxi :  %.2feuroa\n", taxi_lippu);
        printf("(2) : Bussi : %.2feuroa\n", bussi_lippu);
        printf("Paina valintasi, kiitos: ");
        scanf("%d", &valinta);
        switch (valinta) {
            case 1:
                if (varat < taxi_lippu) {
                    printf("Sinulla ei ole varaa taxiin...\n");
                }
                else {
                    printf("Valitsit taxin.\n");
                    varat -= taxi_lippu;
                    printf("Sinulla on nyt %.2feuroa\n", varat);
                }
            break;
            case 2:
                printf("Valitsit bussin.\n");
            varat -= bussi_lippu;
            printf("Sinulla on nyt %.2feuroa\n", varat);
            break;
        }
        if (bussi_lippu > varat && taxi_lippu > varat) {
            printf("Joudut valitettavasti tallustamaan loppumatkan...\n");
            exit(0);
        }
    }

    return 0;
}