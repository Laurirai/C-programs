#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// i could run this program, dont know why.
// tried to do all sorts of fixes, but nothing seemed to work
// also,,, im not sure i even get the exercise.. but thought id return this still
// incase i get a point or two.. :)

int main(void){
  srand((unsigned)time(NULL));
  int users_level;

  const char *bug_report[] = {
    "You've got a minor bug"
    "You've got a mediocre bug"
    "You've got a major bug"
    "Throw your pc out of the window!"
  };

  printf("What debug level do you want to use?\n: ");
  if(scanf("%d",&users_level)!=1){
    fprintf(stderr,"Invalid Input\n");
    return 1;
  }
  set_debug_level(users_level);

  for (int i = 0; i < 5; i++){
    int random_debug_lvl = rand() % 5;
    dprintf(random_debug_lvl, "Debug message %d: %s\n",i,bug_report[random_debug_lvl]);
  }
  return 0;
}