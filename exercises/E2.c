#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float array_1[12]; // defining the arrays
  float array_2[12];
  float tax_rate;  // defining the variables
  float income_limit;
  int over_the_limit_tax_rate;
  int j = 0;

  // asking n saving in arrays/variables
  printf("Enter tax rate: ");
  scanf("%f", &tax_rate);
  getchar();
  printf("Enter income limit: ");
  scanf("%f", &income_limit);
  getchar();
  printf("Enter tax rate for income over the limit : ");
  scanf("%d", &over_the_limit_tax_rate);
  getchar();

  // creating a for loop for asking income for each month
  for (int i = 1; i < 13; i++) {
    printf("Enter the income for month %d: ", i);
    scanf("%f", &array_1[j]);
    getchar();
    j += 1;
  }
  // creating a loop to calculate the taxes and to iterate through the first array and add the taxes to another array
  for (int k = 0; k < 12; k++) {
    if (array_1[k] <= income_limit) {
      array_2[k] = array_1[k] * (tax_rate / 100);
    }
    else {
      array_2[k] = income_limit * (tax_rate / 100) + (array_1[k] - income_limit) * (over_the_limit_tax_rate / 100);
    }
  }

  printf("\nmonth   income      tax\n");
  for (int i = 0; i < 12; i++) {
    printf("%5d %9.2f %9.2f\n", i + 1, array_1[i], array_2[i]);
  }

  return 0;
}