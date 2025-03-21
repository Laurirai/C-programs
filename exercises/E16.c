#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
  int number; // number stored in a node
  struct node *next; // pointer to next node
} node;

int main(void){

  node *head = NULL; // first node in the list
  node *tail = NULL; // last node in the list
  char user_input[100]; // to store the user's input 99 + null
  char *endpointer; // pointer used with strtol to check if the string was converted to a number

  while(1){
    printf("Please enter a number or 'end' to quit:\n");
    if(scanf("%s", user_input) != 1){ // storing
      fprintf(stderr, "ERROR READING THE INPUT\n");
      return 1; // if cant read, exit the program
    }
    if(strcmp(user_input, "end") == 0){
      break; // if end the exit the while loop
    }
    long value = strtol(user_input, &endpointer, 10); // strtol converts string to long int
    if(*endpointer != '\0'){ // the endpointer was set by strtol to the first char that wasn't converted
      // that char will be flagged
      fprintf(stderr, "ERROR, INVALID INPUT\n");
      continue;
    }
    // *new_node will be the address of newly allocated node
    node *new_node = malloc(sizeof(node)); // allocating enough memory for the node structure
    if(new_node == NULL){ // if new node returns null, we couldnt allocate memory
      fprintf(stderr, "ERROR ALLOCATING MEMORY\n");
      return 1; // these return 1's are for safety. If we've had a fatal error, we cannot continue safely
    }
    // since these are pointers we are using arrows instead of dot's
    new_node->number = (int)value; // assing the user's given number to the newnode's number
    // and converting long int to int
    new_node->next = NULL; // setting the next pointer in the new node to null
    if(head == NULL){ // if this is the first iteration, the head should be empty
      // and we can set the tail and the head to the first created node
      head = new_node;
      tail = new_node;
    } else { // if not the first iteration
      tail->next = new_node; // current tail's next pointer is set to the new node
      tail = new_node; // tail is updated to point the new node
    }
  }

  printf("You have entered:\n");
  // to print we create a new node pointer
  // we loop until there is no more nodes
  node *temporary = head;
  while(temporary != NULL){
    printf("%d\n", temporary->number);
    temporary = temporary->next; // setting the new node to the next inline
  }

  // to free the allocated memory
  temporary = head;
  while(temporary != NULL){
    node *to_delete = temporary;
    temporary = temporary->next;
    free(to_delete);
  }
  return 0;
}