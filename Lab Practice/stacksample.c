#include <stdio.h>
#include <stdlib.h>

/* Stack structure definition */
typedef char stackitem;

struct stack {
stackitem  d;
struct stack *next;
};

typedef  struct stack ELEMENT;
typedef  ELEMENT   *POINTER;


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
		  printf("Remove element %c\n", Top1->d);
		  free(Top1);
		}
		else
		  printf("Empty stack.\n");
     }

void print_stack(POINTER Top)
/*Print the contents of the stack. Do not modify the stack in any way. */
	{
		printf("Start printing the stack ...\n");

		/*insert you code here */
    POINTER current;
    current = Top;
    printf("Top ");
    while (current != NULL) {
      printf(" -> %c ", current -> d);
      current = current -> next;
    }

	}

void delete_stack(POINTER *Top)
/* Delete the stack, i.e. remove all items from the stack */
	{
		printf("Start deleting the stack...\n");

		/*insert you code here */
    POINTER top1 = *Top;
    while (Top != NULL) {
      *Top = top1 -> next;
      pop(&top1);
    }
	}

void push_string(POINTER *Top,char *string)
/* Push a string of characters into a stack. */
	{
		printf("Start inserting the string ...\n");

		/*insert you code here */
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

    return 0;
	}
