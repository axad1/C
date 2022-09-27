#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int data;
	struct tree *left, *right;
} Tree;

//	Insert
void insertNode(Tree **root, int data)
{
	if(*root == NULL)
	{
		Tree *newnode = malloc(sizeof(Tree));
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		*root = newnode;
	}
	else if(data < (*root)->data)
		insertNode(&(*root)->left, data);
	else
		insertNode(&(*root)->right, data);
}

//	Delete
Tree* deleteNode(Tree *root, int key)
{
	if(root == NULL)
		return root;

	if(key < root->data)
		root->left = deleteNode(root->left, key);
	else if(key > root->data)
		root->right = deleteNode(root->right, key);
	else
	{
		if(root->left == NULL)
		{
			Tree *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Tree *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			Tree *temp;
			for(temp=root->right; temp->left!=NULL; temp=temp->left);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
}
//	Print
void printTree(Tree *root)
{
	if(!root)
		return;
	printTree(root->left);
	printf("%i\t", root->data);
	printTree(root->right);
}

int main()
{
	Tree *root = NULL;
	for(int i=10; i>5; i--)
		insertNode(&root, i);	
	for(int i=0; i<5; i++)
		insertNode(&root, i+1);
	
	printTree(root);
	puts("");
	printf("root = %d\n", root->data);
	
}
