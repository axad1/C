#include<stdio.h>
int main()
{
//	get position of file pointer
	FILE *in = fopen("asad.txt", "w");
	fpos_t position;
	
	fgetpos(in, &position);
	printf("current pos: %d\n", position);
	
	//	write
	fputs("Hello world", in);
	
//	set position to previos position
	fsetpos(in, &position);
	
	//	write
	fputs("geeks", in);
	
	fgetpos(in, &position);
	printf("current pos: %d\n", position);
}
