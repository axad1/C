#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *next;
}
node;
int main()
{
	node *newnode,*temp,*head = NULL;
//	Add 5 values
	for(int i=0; i<5; i++)
	{
		newnode = malloc(sizeof(node));
		newnode->num = i+1;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
	
//	Add at start
	newnode = malloc(sizeof(node));
	newnode->num = 10;
	newnode->next = head;
	head = newnode;
	
//	Add at end
	newnode = malloc(sizeof(node));
	newnode->num = 30;
	newnode->next = NULL;
	for(temp=head; temp->next!=NULL; temp=temp->next);
	temp->next = newnode;
	
//	Add at position 5
	newnode = malloc(sizeof(node));
	newnode->num = 20;
	temp=head;
	for(int i=1; i<5-1; i++, temp=temp->next);
	newnode->next = temp->next;
	temp->next = newnode;
	
//	print
	for(temp=head; temp!=NULL; temp=temp->next)
	printf("%i\n", temp->num);
	
//	free memory
	while(head!=NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
