#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int key)
{
	struct Node *temp = NULL;
	temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

/*This algorithm insert the node at the first position available in level order*/
void insert(struct Node *node, int key)
{
	queue <struct Node*> q;
	q.push(node);
	while(!q.empty())
	{
		struct Node *temp = q.front();
		q.pop();
		if (!temp->left)
		{
			temp->left = newNode(key);
			break;
		}
		else
			q.push(temp->left);

		if (!temp->right)
		{
			temp->right = newNode(key);
			break;
		}
		else
			q.push(temp->right);
	}
}

/*Traversing in Inorder, Preorder and Postorder*/
void inorder(struct Node *node)
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << "key is : " << node->key << endl;
		inorder(node->right);
	}
}

void preorder(struct Node *node)
{
	if (node != NULL)
	{
		cout << "key is : " << node->key << endl;
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct Node *node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << "key is : " << node->key << endl;
	}
}

void deleteDeepest(struct Node* node, struct Node *right_most_node)
{
	queue<struct Node *> q;
	q.push(node);

	while(!q.empty())	
	{
		struct Node* temp = q.front();
		q.pop();
		
		if (temp == right_most_node)
		{
			temp = NULL;
			delete(right_most_node);
			return;
		}
	
		if (temp->left)
		{
			if (temp->left == right_most_node)
			{
				temp->left = NULL;
				delete(right_most_node);
				return;
			}
			else
				q.push(temp->left);
		}
				
		if (temp->right)
		{
			if (temp->right == right_most_node)
			{
				temp->right = NULL;	
				delete(right_most_node);
				return;	
			}
			else
				q.push(temp->right);
		}
	}
}

/*	This algorithm delete the node by first copying the key_node 
*  	with the right most node data and delete the right most node 
*/
struct Node* deleteNode(struct Node *node, int key)
{
	struct Node *key_node = NULL, *temp = NULL;
	queue<struct Node *> q;
	q.push(node);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if (temp->key == key)
			key_node = temp;
		
		if (temp->left)
			q.push(temp->left);
		
		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL)
	{
		int x = temp->key;
		deleteDeepest(node, temp);
		key_node->key = x; 
	}
	return node;
}

/*Driver program*/
int main()
{
	struct Node *node = NULL;
	int key;
	node = newNode(10);

// Insertion (Level order) 
	while (1)
	{
		cout << "Enter the key or Enter 0 to exit from insertion" << endl;
		cin >> key;
		if (key == 0)
			break;
		insert(node, key);
	}
	
// Traversing
	cout << "##### Inorder #####" << endl;
	inorder(node);

	cout << "##### Preorder #####" << endl;
	preorder(node);

	cout << "##### Postorder #####" << endl;
	postorder(node);

// Deletion
	cout << "Enter the node which you want to delete" << endl;
	cin >> key;
	deleteNode(node, key);

// Traversing after deletion
	cout << "##### Inorder #####" << endl;
	inorder(node);

	return 0;
}
