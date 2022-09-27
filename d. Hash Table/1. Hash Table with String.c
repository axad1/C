#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char str[20];
	struct node *next;
}
node;
unsigned int hash(char *str)
{
	int sum = 0;
	for(int i=0; str[i]!='\0'; i++)
	{
		sum += str[i];
	}
	return sum%26;
}
//	Array of 26 nodes
node *data[26];
int main()
{
//	input 10 names
	for(int i=0; i<10; i++)
	{
		char name[20];
		printf("Enter name: ");
		gets(name);
//		Storing hash value in an integer
		int x = hash(name);
//		Creating a node and storing data
		node *newnode = malloc(sizeof(node));
		sprintf(newnode->str, "%s", name);
		newnode->next = NULL;
//		Manage Linked List
		if(data[x] == NULL)
		{
			data[x]	= newnode;
		}
		else
		{
			newnode->next = data[x];
			data[x] = newnode;
		}
	}
	
//	Print all data
	for(int i=0; i<26; i++)
	{
		node *head = data[i];
		printf("%i", i);
		while(head != NULL)
		{
			printf("\t%s", head->str);
			head = head->next;
		}
		printf("\n");
	}
//	Free Leak Memory
	for(int i=0; i<26; i++)
	{
		while(data[i] != NULL)
		{
			node *head = data[i]->next;
			free(data[i]);
			data[i] = head;
		}
	}
}
