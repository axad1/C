#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node{
	int data;
	struct node *next;
} node;

//	Put
void put(node *table[], int n)
{
	//	Creating a node and storing data
	node *newnode = malloc(sizeof(node));
	newnode->data = n;
	newnode->next = NULL;
	//	Storing hash value in an integer
	int key = n % SIZE;
	//	Manage Linked List
	if(table[key] == NULL)
		table[key] = newnode;
	else
	{
		newnode->next = table[key];
		table[key] = newnode;
	}
}

//	Search
node* searchHash(node *table[], int n)
{
	int key = n % SIZE;
	for(node *head=table[key]; head!=NULL; head=head->next)
	{
		if(n == head->data)
		{
			return head;
		}
	}
	return NULL;
}

//	Delete
void removeHash(node *table[], int n)
{
	int key = n % SIZE;
	node *prenode = NULL;
	for(node *head=table[key]; head!=NULL; head=head->next)
	{
		if(n == head->data)
		{
			if(prenode)
				prenode->next = head->next;
			else
				table[key] = head->next;
			free(head);
			break;
		}
		prenode = head;
	}
}

//	Print
void printHash(node *table[])
{
	for(int i=0; i<SIZE; i++)
	{
		printf("\n%d:", i);
		for(node *head=table[i]; head!=NULL; head=head->next)
			printf("\t%d", head->data);
	}
	puts("");
}

//	Free
void freeHash(node *table[])
{
	for(int i=0; i<SIZE; i++)
	{
		if(table[i] != NULL)
		{
			node *head = table[i]->next;
			free(table[i]);
			table[i] = head;
		}
	}
}

int main()
{
	node *table[SIZE] = {NULL};
	for(int i=0; i<50; i++)
		put(table, i+1);


	printHash(table);
	
//	for(int i=0; i<50; i++)
//		removeHash(table, i+1);
	

	printHash(table);
		
	freeHash(table);
}
