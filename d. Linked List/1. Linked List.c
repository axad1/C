#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *next;
};
int main()
{
//	Creating list
	struct node *list = NULL;
//	Creating temp
	struct node *temp = NULL;
//	Allocate memory to temp
	temp = malloc(sizeof(struct node));
//	Adding values
	(*temp).num = 3;
	(*temp).next = NULL;
//	Link to list
	list = temp;
	
//	Adding 2nd value
	temp = malloc(sizeof(struct node));
	temp->num = 2;
	temp->next = NULL;
//	Link to list
	list->next = temp;
	
//	Adding 3rd value
	temp = malloc(sizeof(struct node));
	temp->num = 1;
	temp->next = NULL;
//	Link to list
	(*((*list).next)).next = temp;
	
//	Adding 4th value
	temp = malloc(sizeof(struct node));
	temp->num = 4;
	temp->next = NULL;
//	Link to list
	(*((*((*list).next)).next)).next = temp;
	
//	Adding 5th value
	temp = malloc(sizeof(struct node));
	temp->num = 5;
	temp->next = NULL;
//	Link to list
	list->next->next->next->next = temp;
	
//	print
	for(temp=list; temp!=NULL; temp=(*temp).next)
	{
		printf("%i\n", (*temp).num);
	}
	
//	free memory
	while(list!=NULL)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}
