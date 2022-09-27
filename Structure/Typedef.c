#include<stdio.h>
typedef struct{
	int roll;
	char name[20];
}person;

int main()
{
	person s;
	s.roll = 12;
	sprintf(s.name,"Asad");
	
	printf("roll = %d\n",s.roll);
	printf("name = %s\n",s.name);
}

