#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions_25.h"


int main(void) {

	node* root = node_init(1);
	root->left = node_init(2);
	root->right = node_init(3);
	root->left->left = node_init(4);
	root->left->right = node_init(5);
	root->left->left->left = node_init(6);
	root->left->left->right = node_init(7);

	printRootNodeValue(root);
	printf("\n");

	int lookupValue = 15;
	if (preorder_traversalSearch2(root, lookupValue))
	{
		printf("Lookup value %d found", lookupValue);

	}
	else
	{
		printf("Lookup value %d not found", lookupValue);
	}

	node* result = preorder_traversalSearch(root, lookupValue);
	if (result)
	{
		printf("\nResult: %d", result->data);

	}
	else
	{
		printf("\nLookup value %d not found", lookupValue);
	}

	return 0;
}
