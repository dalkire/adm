#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int item;
	struct list *next;
} list;

list *search_list(list *l, int x);
void insert_list(list **l, int x);
void print_list(list *l);

int main(int argc, char *argv[])
{
	list *l;
	insert_list(&l, 1);
	insert_list(&l, 2);
	insert_list(&l, 3);
	insert_list(&l, 4);
	insert_list(&l, 5);

	print_list(l);

	return 0;
}

list *search_list(list *l, int x)
{
	if (l == NULL)
		return NULL;
	if (l->item == x)
		return l;
	else
		return search_list(l->next, x);
}

void insert_list(list **l, int x)
{
	list *p;

	p = malloc(sizeof(list));
	p->item = x;
	p->next = *l;
	*l = p;
}

void print_list(list *l)
{
	if (l->next == NULL) {
		printf("%d\n", l->item);
	} else {
		printf("%d, ", l->item);
		print_list(l->next);
	}
}

