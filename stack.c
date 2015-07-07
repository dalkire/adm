/* Linked list implementation of a stack.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int value;
	struct stack *next;
} stack;

stack *pop(stack **s);

int main(int argc, char *argv[])
{
	

	return EXIT_SUCCESS;
}

stack *pop(stack **s)
{
	return *s;
}
