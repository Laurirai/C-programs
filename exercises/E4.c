#include <stdio.h>


int read_integer(void) {
    int number;
    printf("Enter positive numbers or negative to stop: ");
    scanf("%d", &number);
    return number;
}

int main(void) {
    int sum = 0;
    int count = 0;
    float average;
    while (1) {
        int value = read_integer();
        if (value < 0) {
            if (count == 0) {
                printf("You haven't entered a single positive number yet...\n");
            }
            else {
                average = (float)sum / count;
                printf("You've entered %d positive numbers. The average is: %.3f", count, average);

            }
            break;
        }
        if (value > 0) {
            count++;
            sum += value;
        }
    }
    return 0;
}