/*
void listStart(struct node **head, int data)
void listEnd(struct node **head, int data)
int isEmpty(struct node *head)
int listIndex(struct node *head, int index)
void listAddIndex(struct node **head, int index, int data)
void listDelStart(struct node **head)
void listDelEnd(struct node **head)
void listDelIndex(struct node **head, int index)
void listReverse(struct node **head)
void freeList(struct node **head)
void printList(struct node *head)
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} List;

int COUNT=0;

//	Add Start
void listStart(struct node **head, int data)
{
	COUNT++;
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

//	Add End
void listEnd(struct node **head, int data)
{
	COUNT++;
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	if(!*head)
		*head = newnode;
	else
	{
		struct node *temp;
		for(temp=*head; temp->next!=NULL; temp=temp->next);
		temp->next = newnode;
	}
}

//	listIndex
int listIndex(struct node *head, int index)
{
	if(index >= COUNT)
		return -1;
	struct node *temp = head;
	for(int i=0; i<index && i<COUNT; i++, temp=temp->next);
	return temp->data;
}

//	listAddIndex
void listAddIndex(struct node **head, int index, int data)
{
	if(index==0)
		listStart(head, data);
	else if(index == COUNT)
		listEnd(head, data);
	else if(index > COUNT)
		return;
	else
	{
		COUNT++;
		struct node *newnode = malloc(sizeof(struct node));
		newnode->data = data;
		struct node *temp=*head;
		for(int i=0; i<index-1; i++, temp=temp->next);
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

//	isEmpty
int isEmpty(struct node *head)
{
	if(!head)
	{
		puts("----- list is empty -----");
		return 1;
	}
	return 0;
}

//	Delete Start
void listDelStart(struct node **head)
{
	if(!isEmpty(*head))
	{
		struct node *temp = *head;
		*head = temp->next;
		free(temp);
		COUNT--;
	}
}

//	Delete End
void listDelEnd(struct node **head)
{
	if(!isEmpty(*head))
	{
		if(!(*head)->next)
		{
			struct node *temp = *head;
			*head = NULL;
			free(temp);
		}
		else
		{
			struct node *temp, *prenode;
			for(temp=*head; temp->next!=NULL; temp=temp->next)
				prenode = temp;
			prenode->next = NULL;
			free(temp);
		}
		COUNT--;
	}
}

//	listDelIndex
void listDelIndex(struct node **head, int index)
{
	if(index == 0)
		listDelStart(head);
	else if(index == COUNT-1)
		listDelEnd(head);
	else if(index >= COUNT)
		return;
	else
	{
		struct node *delnode, *temp = *head;
		for(int i=0; i<index-1; i++, temp=temp->next);
		delnode = temp->next;
		temp->next = delnode->next;
		free(delnode);
		COUNT--;
	}
}


//	Reverse
void listReverse(struct node **head)
{
	struct node *newnode = *head, *temp = *head;
	//	Create a node to remember previous
	struct node *prenode = NULL;
	//	iterate through all nodes
	while(temp!=NULL)
	{
	//	remember the next node in temp
		temp = temp->next;
	//	set current node next to previous node
		newnode->next = prenode;
	//	set previous node to current node
		prenode = newnode;
	//	set current node to next node
		newnode = temp;
	}
	//	set head to prenode which is current last node
	*head = prenode;
}

//	Print List
void printList(struct node *head)
{
	if(!isEmpty(head))
	{
		for(struct node *temp=head; temp!=NULL; temp=temp->next)
			printf("%d\t", temp->data);
		puts("");
	}
}

//	Free
void freeList(struct node **head)
{
	while(*head!=NULL)
	{
		struct node *temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	COUNT = 0;
}
