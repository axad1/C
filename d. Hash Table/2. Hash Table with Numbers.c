#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node{
	int data;
	struct node *next;
} node;
unsigned int hash(int n)
{
	return n%SIZE;
}

int main()
{
	node *table[SIZE] = {NULL};
	for(int i=0; i<50; i++)
	{
		int n = i+1;
//		printf("Enter number: ");
//		scanf("%d", &n);
		//	Storing hash value in an integer
		int key = hash(n);
		//	Creating a node and storing data
		node *newnode = malloc(sizeof(node));
		newnode->data = n;
		newnode->next = NULL;
		//	Manage Linked List
		if(table[key] == NULL)
			table[key] = newnode;
		else
		{
			newnode->next = table[key];
			table[key] = newnode;
		}
	}
	
	//	Print all data
	for(int i=0; i<SIZE; i++)
	{
		printf("\n%d:", i);
		for(node *head=table[i]; head!=NULL; head=head->next)
			printf("\t%d", head->data);
	}
	//	Free Leak Memory
	for(int i=0; i<SIZE; i++)
	{
		while(table[i] != NULL)
		{
			puts("ok");
			node *head = table[i]->next;
			free(table[i]);
			table[i] = head;
		}
	}
}
