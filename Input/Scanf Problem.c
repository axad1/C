#include<stdio.h>
int main()
{
//	Using %[^\n]%*c inside scanf
/*	gets() only terminates when either:
		end-of-file is reached
		n-1 characters are read
		the newline character is read
	problem is scanf() reads and leaves a newline character in the buffer
	Solution:
	We can make scanf() to read a new line by using an extra \n
		scanf(“%d\n”, &x)
		scanf(“%d “, &x) also works
	We can add a getchar() after scanf() to read an extra newline.
*/
	int n;
	char name[10];
	
	scanf("%d\n", &n);
	gets(name);
	
	//	also limit inupt
//	scanf("%5s", s);
	
	printf("n = %d\n", n);
	printf("name = %s\n", name);
}
