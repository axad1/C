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
//	Add 10 values
	for(int i=0; i<10; i++)
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
	
//	Reverse
	newnode=temp=head;
//	Create a node to remember previous
	node *prenode = NULL;
//	iterate through all nodes
	while(temp!=NULL)
	{
//		remember the next node in temp
		temp = temp->next;
//		set current node next to previous node
		newnode->next = prenode;
//		set previous node to current node
		prenode = newnode;
//		set current node to next node
		newnode = temp;
	}
//	set head to prenode which is current last node
	head = prenode;

//	print
	for(temp=head; temp!=NULL; temp=temp->next)
	printf("%i\t", temp->num);
	
//	free memory
	while(head!=NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
