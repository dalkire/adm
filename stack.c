/* Linked list implementation of a stack.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int item;
	struct stack *next;
} stack;

void push(stack **s, int x);
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

	return EXIT_SUCCESS;
}

void push(stack **s, int x)
{
	stack *node;

	node = malloc(sizeof(stack));
	node->item = x;
	node->next = *s;
	*s = node;
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
