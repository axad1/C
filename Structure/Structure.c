#include<stdio.h>
struct Person{
	int roll;
	char name[20];
};

int main()
{
	struct Person s;
	s.roll = 12;
	sprintf(s.name,"Asad");
	
	printf("roll = %d\n",s.roll);
	printf("name = %s\n",s.name);
}

