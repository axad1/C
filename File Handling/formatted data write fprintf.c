#include<stdio.h>
int main()
{
	FILE *out;
	if((out = fopen("text.txt","w")) == NULL)
	{
		printf("Errorr");
		return 1;
	}
	int roll,marks;
	char grade;
	printf("Enter roll no, marks and grade\n");
	scanf("%d %d %c", &roll, &marks, &grade);
	fprintf(out,"%d\t%d\t%c",roll, marks, grade);
	fclose(out);
}
