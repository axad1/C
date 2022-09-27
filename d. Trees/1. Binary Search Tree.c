/*
Allows us to maintain a sorted list.
Search for a number in O(log(n)) time.
All nodes of left subtree are less than the root node.
All nodes of right subtree are more than the root node.
Both subtrees of each node are also BSTs.
*/

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
void deleteNode(Tree **root, int key)
{
	if(!*root)
		return;

	if(key < (*root)->data)
		deleteNode(&(*root)->left, key);
	else if(key > (*root)->data)
		deleteNode(&(*root)->right, key);

	// We reach here when root is the node to be deleted.
	if((*root)->left == NULL)
	{
		Tree *temp = *root;
		*root = (*root)->right;
		free(temp);
	}
	else if((*root)->right == NULL)
	{
		Tree *temp = *root;
		*root = (*root)->left;
		free(temp);
	}
	// If both children exist
	else
	{
		Tree **temp;
		for(temp=&(*root)->right; (*temp)->left!=NULL; *temp=(*temp)->left);
		(*root)->data = (*temp)->data;		
		deleteNode(&*temp, (*temp)->data);
	}
}

//	Print Inorder Traversal
void printTree(Tree *root)
{
	if(!root)
		return;
	printTree(root->left);
	printf("%i\t", root->data);
	printTree(root->right);
}

//	Free
void freeTree(Tree *root)
{
	if(!root)
		return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

//	isBST
int isBST(Tree *root, Tree *left, Tree *right)
{
	if(!root)
		return 1;

	// it is for the right side
	if(left!=NULL && root->data<left->data)
		return 0;

	// it is for the left side
	if(right!=NULL && root->data>=right->data)
		return 0;

	return isBST(root->left, NULL, root) && isBST(root->right, root, NULL);
}

int main()
{
	Tree *root = NULL;
	insertNode(&root, 5);
	insertNode(&root, 5);
	insertNode(&root, 5);
	insertNode(&root, 5);
	insertNode(&root, 5);
	
	printTree(root);
	puts("");
	
	deleteNode(&root, 5);
	printTree(root);

	freeTree(root);

}
