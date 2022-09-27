#include <stdio.h>
int main(void)
{
	int a[10], i, n;
	for(int k=0; k<10; k++)
	{
    	n = k;
    	//	convert to binary
    	for(i=0; n>0; i++)
    	{
    		a[i] = n%2;
    		n = n/2;
		}
		
		//	print
		printf("%d = ", k);
		for(i=i-1;i>=0; i--)
		printf("%d", a[i]);
		
		//	newline
		printf("\n");
	}
}
