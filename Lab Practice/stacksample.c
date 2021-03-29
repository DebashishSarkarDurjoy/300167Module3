#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Stack structure definition */
typedef char stackitem;

struct stack {
stackitem  d;
struct stack *next;
};

typedef  struct stack ELEMENT;
typedef  ELEMENT* POINTER;


void push(POINTER *Top, stackitem a)
/* Put item a into the top of the stack */
     {
		POINTER temp;
		temp = malloc(sizeof(ELEMENT));
		temp->d = a;
		temp->next = *Top;
		*Top = temp;
		printf("Insert element %c\n", temp->d);
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

void print_stack(POINTER Top)
/*Print the contents of the stack. Do not modify the stack in any way. */
	{
		printf("\nStart printing the stack ...\n");

		/*insert you code here */
    POINTER current = Top;
    printf("\n\tTop ");
    while (current != NULL) {
      printf(" -> %c", current->d);
      current = current -> next;
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

void push_string(POINTER *Top, char *string)
/* Push a string of characters into a stack. */
	{
		printf("\nStart inserting the string ...\n");

		/*insert you code here */
    char stringChar;
    stringChar = string[0];
    int index = 0;
    while(stringChar != '\0') {
      push(Top, stringChar);
      index++;
      stringChar = string[index];
    }

	}

int main(void)
	{

		POINTER top;
		top= (POINTER) NULL;
		stackitem A='A';
		stackitem B='B';
		char *C="12345";
		//printf("C is %s\n", C);
		push(&top,A);
		push(&top,B);
		print_stack(top);
		pop(&top);
		pop(&top);
		print_stack(top);
		push_string(&top,C);
		print_stack(top);
		delete_stack(&top);
		print_stack(top);

	}
