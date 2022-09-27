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
	
//	Remove from start
	temp = head;
	head = head->next;
	free(temp);
	
//	Remove from end
	for(temp=head; temp->next!=NULL; temp=temp->next)
	newnode = temp;
	newnode->next = NULL;
	free(temp);
	
//	Remove from position 4
	temp = head;
//	iterate to position 3
	for(int i=1; i<4-1; i++, temp=temp->next);
//	save the position 4 in newnode
	newnode = temp->next;
//	set position 3 next to position 5
	temp->next = temp->next->next;
//	free pos 4
	free(newnode);
	
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
