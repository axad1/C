#include<stdio.h.>

int main()
{
	char s[5][20] = {"ali","hussian","kamran","sahil","asad"};
	
	for(int i=0; i<5; i++)
		puts(s[i]);
		
		
	char *c[] = {"asad", "zulfiqar", "shahid"};
	
	for(int i=0; i<sizeof(c)/sizeof(char*); i++)
		puts(c[i]);
		
}
