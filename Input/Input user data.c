//input name, age and address of user and print 10.13 chapter 10
#include<stdio.h>
int main()
{
	char name[20],address[20];
	int age;
	printf("Enter full name : ");
	gets(name);
	printf("Enter age : ");
	scanf("%d",&age);
	printf("Enter address : ");
	scanf("%s",address);
	
//	print
	printf("\n---output---\n");
	printf("Name = %s\n",name);
	printf("Age = %d\n",age);
	printf("Address = %s\n",address);
}
