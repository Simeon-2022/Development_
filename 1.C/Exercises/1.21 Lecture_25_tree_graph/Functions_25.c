
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions_25.h"


node* node_init(int data) {

	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void node_remove_root(node** node) {

	if (*node == NULL)
	{
		return;
	}

	node_remove_root(&(*node)->left);
	node_remove_root(&(*node)->right);

	free(*node);
	*node = NULL;
}

void inorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

void postorder_iter(node* root) {
	if (root == NULL) {
		return;
	}

	postorder_iter(root->left);
	postorder_iter(root->right);
}

void printRootNodeValue(node* root) {

	postorder_iter(root);
	printf("Root value: %d", root->data);
}

_Bool preorder_traversalSearch2(node* root, int value) {
	if (root == NULL) {
		return false;
	}

	if (root->data == value) {
		return true;
	}

	if (preorder_traversalSearch2(root->right, value)) {
		return true;
	}

	if (preorder_traversalSearch2(root->left, value)) {
		return true;
	}

	return false;
}

node* preorder_traversalSearch(node* root, int value) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == value) {
		return root;
	}

	node* found_node = preorder_traversalSearch(root->right, value);
	if (found_node != NULL) {
		return found_node;
	}

	found_node = preorder_traversalSearch(root->left, value);
	if (found_node != NULL) {
		return found_node;
	}

	return NULL;
}

int measureTreeHeight(node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int left_height = measureTreeHeight(root->left);
		int right_height = measureTreeHeight(root->right);

		if (left_height > right_height) {
			return left_height + 1;
		}
		else {
			return right_height + 1;
		}
	}
}

int treeValuesSum(node* root) {
	if (root == NULL) {
		return 0;
	}

	return root->data + treeValuesSum(root->left) + treeValuesSum(root->right);
}

MinMax getMinMax(node* root) {
	MinMax minMax;

	if (root == NULL) {
		minMax.min = INT_MAX;
		minMax.max = INT_MIN;
		return minMax;
	}

	MinMax leftMinMax = getMinMax(root->left);
	MinMax rightMinMax = getMinMax(root->right);

	minMax.min = min(root->data, min(leftMinMax.min, rightMinMax.min));
	minMax.max = max(root->data, max(leftMinMax.max, rightMinMax.max));

	return minMax;
}

int isBST(node* root) {
	if (root == NULL) {
		return 1;
	}

	if (root->left != NULL && root->left->data > root->data) {
		return 0;
	}

	if (root->right != NULL && root->right->data < root->data) {
		return 0;
	}

	if (!isBST(root->left) || !isBST(root->right)) {
		return 0;
	}

	return 1;
}
