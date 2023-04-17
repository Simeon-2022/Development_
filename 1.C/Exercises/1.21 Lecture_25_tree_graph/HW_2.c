#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Functions_25.h"

int main(void) {

	node* root = node_init(1);
	root->left = node_init(2);
	root->right = node_init(3);
	root->left->left = node_init(4);
	root->left->right = node_init(5);
	root->left->left->left = node_init(6);
	root->left->left->right = node_init(7);

	inorder_traversal(root);
	printf("\n");
	preorder_traversal(root);
	printf("\n");
	postorder_traversal(root);
	printf("\n");

	return 0;
}
