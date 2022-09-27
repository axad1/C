#include<stdio.h>
int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {1,6};
	
	int flag;
	for(int i=0; i<sizeof(b)/sizeof(int); i++)
	{
		flag = 0;
		for(int j=0; j<sizeof(a)/sizeof(int); j++)
		{
			if(b[i] == a[j])
			{
				flag = 1;
				break;
			}
		}
	}
	if(flag == 1)
		puts("yes b is a subtree");
	else
		puts("no");
}
