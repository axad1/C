#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
int main()
{
	node *list, *head = NULL;
	for(int i=0; i<5; i++)
	{
		node *temp = malloc(sizeof(node));
		temp->data = i+1;
		temp->next = NULL;
		if(!head)
		{
			head = list = temp;
		}
		else
		{
			list->next = temp;
			list = temp;
		}
	}
	
//	find the number of nodes
	int count;
	for(list=head, count=0; list!=NULL; list=list->next, count++)
	printf("%d\t", list->data);
//	iterate to the middle
	list = head;
	for(int i=0; i<count/2; i++, list=list->next);
//	print middle
	printf("\nmiddle = %d", list->data);
	
	//	Free
	while(head != NULL)
	{
		list = head->next;
		free(head);
		head = list;
	}
}
