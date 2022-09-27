#include<stdio.h>
int main()
{
	FILE *in = fopen("text.txt","r");
	if(!in)
	{
		printf("Errorr");
		return 1;
	}
	int roll,marks;
	char grade;
	while(fscanf(in,"%d\t%d\t%c",&roll, &marks, &grade) != EOF)
		printf("%d\t%d\t%c\n",roll,marks,grade);
	fclose(in);
}
