#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int item;
	struct list *next;
} list;

list *search_list(list *l, int x);
void insert_list(list **l, int x);
void print_list(list *l);
void print_node(list *l);
list *predecessor_list(list *l, int x);
void delete_list(list **l, int x);

int main(int argc, char *argv[])
{
	list *l;
	insert_list(&l, 1);
	insert_list(&l, 2);
	insert_list(&l, 3);
	insert_list(&l, 4);
	insert_list(&l, 5);

	print_list(l);
	print_node(search_list(l, 3));
	print_node(predecessor_list(l, 3));
	delete_list(&l, 3);
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

void print_node(list *l)
{
	if (l->item)
		printf("Node: %d\n", l->item);
}

list *predecessor_list(list *l, int x)
{
	if (l == NULL || l->next == NULL) {
		printf("Error: predecessor sought on null list.\n");
		return NULL;
	}

	if ((l->next)->item == x)
		return l;
	else
		return predecessor_list(l->next, x);
}

void delete_list(list **l, int x)
{
	list *p;
	list *pred;

	p = search_list(*l, x);
	if (p != NULL) {
		pred = predecessor_list(*l, x);
		print_node(pred);
		if (pred == NULL)
			*l = p->next;
		else
			pred->next = p->next;

		free(p);
	}
}
