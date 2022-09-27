#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char str[20];
	struct node *next;
}
node;
//	Array of 26 nodes
node *data[26];
//	Hash function
unsigned int hash(char *str);
//	Print function
void print();
//	Clear Leak memory function
void leak();
//	Main
int main()
{
	for(int i=0; i<4; i++)
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
	print();
	
//	Delete
	char name[20];
	printf("\nEnter name to delete: ");
	gets(name);
	int x = hash(name);
	for(node *temp=data[x], *head=data[x]; temp!=NULL; temp=temp->next)
	{
		if(strcmp(temp->str, name) == 0)
		{
//			first occurance case
			if(temp == data[x])
			{
				data[x] = temp->next;
			}
//			last case occurance
			else if(temp->next == NULL)
			{
				head->next = temp->next;
			}
//			middle case
			else
			{
				head->next = temp->next;
			}
		}
//		prenode head update
		head = temp;
	}
	
	print();
	
//	Free Leak Memory
	leak();
}

unsigned int hash(char *str)
{
	int sum = 0;
	for(int i=0; str[i]!='\0'; i++)
	{
		sum += str[i];
	}
	return sum%26;
}

void print()
{
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
}

void leak()
{
	for(int i=0; i<26; i++)
	{
		if(data[i] != NULL)
		{
			node *head = data[i]->next;
			free(data[i]);
			data[i] = head;
		}
	}
}
