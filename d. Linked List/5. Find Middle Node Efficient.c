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
	
//	Find middle
	node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
	{
    	slow = slow->next;
    	fast = fast->next->next;
    }
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
