/*
 * Binary Search Tree implementation.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int item;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} tree;

void insert_tree(tree **l, int x, tree *parent);
void traverse_tree(tree *l);

int main (int argc, char *argv[])
{
	tree *t;

	insert_tree(&t, 5, NULL);
	insert_tree(&t, 1, NULL);
	insert_tree(&t, 7, NULL);
	insert_tree(&t, 2, NULL);
	insert_tree(&t, 8, NULL);
	insert_tree(&t, 9, NULL);

	traverse_tree(t);

	return EXIT_SUCCESS;
}

void insert_tree(tree **l, int x, tree *parent)
{
	tree *p;

	/*
	 * If the pointer to the search subtree is empty,
	 * we have found the location for insertion.
	 */
	if (*l == NULL) {
		p = malloc(sizeof(tree));
		p->item = x;
		p->left = NULL;
		p->right = NULL;
		p->parent = parent;
		*l = p;

		return;
	}

	if (x < (*l)->item)
		insert_tree(&((*l)->left), x, *l);
	else
		insert_tree(&((*l)->right), x, *l);
}

void traverse_tree(tree *l)
{
	if (l != NULL) {
		traverse_tree(l->left);
		printf("-%d-", l->item);
		traverse_tree(l->right);
	}
}
