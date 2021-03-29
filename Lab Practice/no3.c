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
  printf("\nChoose an option:[-1 to exit]\n");

  printf("1. Push one character onto the stack.\n");
  printf("2. Pop the top character from stack.\n");
  printf("3. Push a string of characters into the stack.\n");
  printf("4. Print the contents of the stack.\n");
  printf("5. Delete the stack.\n");
  printf("6. Reverse top two elements of the stack.\n");
  printf("7. Reverse the stack.\n");
  printf(">>");
  scanf("%d", &input);
  return input;
}

void push(POINTER* Head) {
  stackitem input;
  printf("\nEnter a character to push: ");
  scanf(" %c", &input);

  if (Head == NULL) {
    ELEMENT* newNode = malloc(sizeof(ELEMENT));
    newNode -> d = input;
    newNode -> next = NULL;
    *Head = newNode;
  }
  else {
    ELEMENT *newNode = malloc(sizeof(ELEMENT));
    newNode -> next = *Head;
    newNode -> d = input;
    *Head = newNode;
  }
}

void push2(POINTER *Top, stackitem a)
/* Put item a into the top of the stack */
     {
		POINTER temp;
		temp = malloc(sizeof(ELEMENT));
		temp->d = a;
		temp->next = *Top;
		*Top = temp;
		printf("Insert element %c\n", temp->d);
     }

void showStack(POINTER Head) {
  ELEMENT *current = Head;
  printf("Top ");
  while(current != NULL) {

    printf(" -> %c ", current -> d);
    current = current -> next;
  }
  printf("\n");
}

void pop(POINTER *Top)
/* Remove the top item */
    {
		POINTER Top1 = *Top;
		if (Top != NULL)
		{
		  *Top = Top1->next;
		  printf("\nRemove element %c\n", Top1->d);
		  free(Top1);
		}
		else
		  printf("\nEmpty stack.\n");
    }

void push_string(POINTER *Top, char *string)
    /* Push a string of characters into a stack. */
    	{
    		printf("\nStart inserting the string ...\n");

    		/*insert you code here */
        char stringChar;
        stringChar = string[0];
        int index = 0;
        while(stringChar != '\0') {
          push2(Top, stringChar);
          index++;
          stringChar = string[index];
        }

    	}

void delete_stack(POINTER *Top)
    /* Delete the stack, i.e. remove all items from the stack */
    	{
    		printf("\nStart deleting the stack...\n");

    		/*insert you code here */
        POINTER temp = *Top;
        while (*Top != NULL) {
          temp = *Top;
          *Top = (*Top) -> next;
          pop(&temp);
        }

    	}

void exchange(POINTER *Top) {
  POINTER nextNode = (*Top) -> next;
  (*Top) -> next = nextNode -> next;
  nextNode -> next = *Top;
  *Top = nextNode;
}

void reverseStack(POINTER *Top) {
  POINTER previous = Top;
  POINTER current = previous -> next;
  POINTER next = current -> next;

  while (next != NULL) {
    current -> next = previous;
    current -> 
  }
}

int main(void) {
  int option;
  char *string;
  POINTER Top = NULL;

  while(option > 0) {
    option = menu();
    switch(option) {
      case 1: push(&Top);
              break;
      case 2: pop(&Top);
              break;
      case 3:
              printf("\nEnter string to push: ");
              scanf("%s", string);
              push_string(&Top, string);
              break;
      case 4: showStack(Top);
              break;
      case 5: delete_stack(&Top);
              break;
      case 6: exchange(&Top);
              break;
      case 7: reverseStack(&Top);
              break;

    }
  }



  return 0;
}
