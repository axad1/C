/*
void push(struct node **head, int data)
int isEmpty(struct node *head)
void pop(struct node **head)
int top(struct node *head)
void printStack(struct node *head)
void freeStack(struct node *head)
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} Stack;

//	Push
void push(struct node **head, int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}
//	isEmpty
int isEmpty(struct node *head)
{
	//	return 0 if null else 1
	return !head;
}
//	Pop
void pop(struct node **head)
{
	if(!isEmpty(*head))
	{
		struct node *temp = *head;
		*head = temp->next;
		free(temp);
	}
	else
		puts("----- stack is empty -----");
}

//	Top
int top(struct node *head)
{
	if(!isEmpty(head))
		return head->data;
	else
		return -1;
}

//	Print Stack
void printStack(struct node *head)
{
	if(!isEmpty(head))
	{
		for(struct node *temp=head; temp!=NULL; temp=temp->next)
			printf("%d\t", temp->data);
		puts("");
	}
}

//	Free
void freeStack(struct node **head)
{
	while(*head!=NULL)
	{
		struct node *temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
