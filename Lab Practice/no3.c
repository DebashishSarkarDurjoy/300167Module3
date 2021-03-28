#include <stdio.h>
#include <stdlib.h>

typedef char stackitem;

struct stack {
  stackitem d;
  struct stack *next;
};

typedef struct stack ELEMENT;
typedef ELEMENT *POINTER;



int menu(void) {
  int input = 0;
  printf("\nChoose an option:\n");

  printf("1. Push one character onto the stack: ");
  scanf("%d", &input);
  return input;
}

ELEMENT* push(ELEMENT *Head) {
  int input;
  printf("\nEnter a number to push: ");
  scanf("%d", &input);

  if (Head == NULL) {
    ELEMENT* newNode = malloc(sizeof(ELEMENT));
    newNode -> d = input;
    newNode -> next = NULL;
    Head = newNode;
    return newNode;
  }
  else {
    ELEMENT *newNode = malloc(sizeof(ELEMENT));
    newNode -> next = Head;
    newNode -> d = input;
    Head = newNode;
    return newNode;
  }
}

void showStack(ELEMENT *Head) {
  ELEMENT *current = Head;
  printf("Top ");
  while(current != NULL) {

    printf(" -> %d ", current -> d);
    current = current -> next;
  }
  printf("\n");
}

int main(void) {
  int option;
  POINTER *Top = NULL;

  while(option > 0) {
    option = menu();
    switch(option) {
      case 1: Top = push(Top);
              showStack(Top);
              break;
      case 2: Top = pop(Top);
              showStack(Top);
              break;
      
    }
  }



  return 0;
}
