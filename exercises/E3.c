#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int number_of_students; // alustetaan muuttujat ja kystään oppilaiden määrä joka tallennetaan myös muuttujaan

  printf("How many students: ");
  scanf("%d", &number_of_students);
  int grades[number_of_students];
  for (int i = 0; i < number_of_students; i++) {
    grades[i] = -1;
  }
  int student_number;
  int grade;
  while (1){ // boolean looppi oppilaiden kysymiseen
    printf("Enter student number (1-%d): or 0 to stop: ", number_of_students);
    scanf("%d", &student_number);

    if (student_number == 0) { // tarkastellaan vastauksia
      break;
    }

    if (student_number < 1 or student_number > number_of_students) { // numeron tarkastusta
      printf("Invalid student number!\n");
      continue;
    }

    while (1) { // looppi arvosanojen kysyntään
      printf("Enter grade (0 - 5) for student number %d or -1 to cancel: ", student_number);
      scanf("%d", &grade);

      //printf("Debug: grade = %d\n", grade); else lauseen debuggaus

      if (grade == -1) {
        break;
      }

      if (grade >= 0 && grade <= 5) { // arvosanan tarkastusta
        grades[student_number - 1] = grade;
        break;
      }
      else {
          printf("Invalid grade!\n");
      }

    }
  }

  printf("\nStudent\tGrade\n"); // printtaus loopissa ja asettelua
  for (int i = 0; i < number_of_students; i++) {
    if (grades[i] == -1) {
      printf("%d\tN/A\n", i +1);
    }
    else {
      printf("%d\t%d\n", i + 1, grades[i]);
    }
  }

  return 0;
}