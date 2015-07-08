/*
 * Linked list implementation of a stack.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int item;
	struct stack *next;
} stack;

void push(stack **s, int x);
stack *pop(stack **s);
void print_stack(stack *s);

int main(int argc, char *argv[])
{
	stack *s = NULL;

	push(&s, 1);
	push(&s, 3);
	push(&s, 5);
	push(&s, 7);
	push(&s, 9);

	print_stack(s);

	pop(&s);
	printf("pop\n");

	print_stack(s);

	pop(&s);
	printf("pop\n");

	print_stack(s);

	return EXIT_SUCCESS;
}

/*
 * sp is a pointer to the pointer to the top node of the stack,
 * so contains the address of top pointer.
 */
stack *pop(stack **sp)
{

	/*
	 * popped is a pointer to a stack node.
	 * Here we set it equal to what sp is pointing to,
	 * which means it now contains the address of the top node.
	 */
	stack *popped = *sp;

	/*
	 * If our pointers don't point, we are done here.
	 */
	if (sp == NULL || *sp == NULL) {
		printf("Error: trying to pop an empty stack");
		return NULL;
	}

	/*
	 * Change top pointer to the address of the second node
	 * so that it is our new top.
	 */
	*sp = (*sp)->next;

	return popped;
}

void push(stack **sp, int x)
{
	stack *np;

	np = malloc(sizeof(stack));
	np->item = x;
	np->next = *sp;
	*sp = np;
}

void print_stack(stack *s)
{
	if (s->next == NULL) {
		printf("%d\n", s->item);
	} else {
		printf("%d, ", s->item);
		print_stack(s->next);
	}
}
