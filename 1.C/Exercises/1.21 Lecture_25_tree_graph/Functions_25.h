#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef struct node {

	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct {
	int min;
	int max;
} MinMax;

node* node_init					(int data);
void node_remove_root			(node** node);
void inorder_traversal			(node* root);
void preorder_traversal			(node* root);
void postorder_traversal		(node* root);
void postorder_iter				(node* root);
void printRootNodeValue			(node* root);
_Bool preorder_traversalSearch2	(node* root, int value);
node* preorder_traversalSearch	(node* root, int value);
int measureTreeHeight			(node* root);
int treeValuesSum				(node* root);
MinMax getMinMax				(node* root);
int isBST						(node* root);
#endif // !FUNCTIONS_H
