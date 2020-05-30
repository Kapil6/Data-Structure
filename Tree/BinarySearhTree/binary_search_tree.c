#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};

/*This function Search the node from the tree*/
struct Node* searching(struct Node *node, int key)
{
	if (node == NULL || node->key == key)
		return node;
	
	if (node->key < key)
		return searching(node->right, key);
	
	return searching(node->left, key);
}

/*Inorder traversal of tree*/
void inorder(struct Node *node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d ", node->key);
		inorder(node->right);
	}
}

/*Function which creates the node*/
struct Node* newNode(int key)
{
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	
	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}

/*Insertion algorithm*/
struct Node* insert(struct Node *node, int key)
{
	if (node == NULL)
		return newNode(key);
	else {
		if (key <= node->key)
			node->left = insert(node->left, key);
		else
			node->right = insert(node->right, key);
	}
	return node;
}

struct Node* minValueNode(struct Node* node)
{
	struct Node *current = node;
	
	while(current && current->left != NULL)
		current = current->left;

	return current;
}

/*This function delete the node from the tree*/
struct Node* deleteNode(struct Node *node, int key)
{
	if (node == NULL)
		return node;
	
	if (key < node->key)
		node->left = deleteNode(node->left, key);
	else if (key > node->key)
		node->right = deleteNode(node->right, key);
	else 
	{
		if (node->left == NULL)
		{
			struct Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			struct Node *temp = node->left;
			free(node);
			return temp;
		}			
	
		struct Node* temp = minValueNode(node->right);
		node->key = temp->key;
		node->right = deleteNode(node->right, temp->key);
	}

	return node;
}

/*Driver program*/
int main()
{
	struct Node *root = NULL, *node_40 = NULL;
	int key;

// Create BST
	root = insert(root, 50);

// Insertion
	insert(root, 70);
	insert(root, 30);
	insert(root, 40);
	insert(root, 20);
	insert(root, 60);
	insert(root, 80);

// Traversing
	inorder(root);
	
// Searching node which has key equal to 40
	searching(root, 40);

// Deletion
	printf("\nEnter the key of the node which you want to delete\n");
	scanf("%d", &key);
	deleteNode(root, key);

// Traversing
	inorder(root);

	return 0;	
}
