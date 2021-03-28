#include <stdio.h>
#include <stdlib.h>

typedef char stackitem;

struct stack {
  stackitem d;
  struct stack *next;
};

typedef struct stack ELEMENT;
typedef ELEMENT* POINTER;



int menu(void) {
  int input = 0;
  printf("\nChoose an option:\n");

  printf("1. Push one character onto the stack.\n");
  printf("2. Pop the top character from stack.\n");
  printf("3. Push a string of characters into the stack.\n");
  printf("4. Print the contents of the stack.\n");
  printf("5. Delete the stack.\n");
  printf(">>");
  scanf("%d", &input);
  return input;
}

ELEMENT* push(ELEMENT *Head) {
  stackitem input;
  printf("\nEnter a character to push: ");
  scanf(" %c", &input);

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

    printf(" -> %c ", current -> d);
    current = current -> next;
  }
  printf("\n");
}

// ELEMENT* pop(POINTER *Top) {
//
// }

int main(void) {
  int option;
  POINTER Top = NULL;

  while(option ) {
    option = menu();
    switch(option) {
      case 1: Top = push(Top);
              break;
      // case 2: Top = pop(Top);
      //         showStack(Top);
      //         break;
      case 4: showStack(Top);
              break;
    }
  }



  return 0;
}
