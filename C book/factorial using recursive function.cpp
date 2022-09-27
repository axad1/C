#include<stdio.h>
int fact(int);
int main()
{
	int n,ans;
	printf("Enter a number:");
	scanf("%d",&n);
	ans=fact(n);
	printf("Factorial is:%d",ans);
}
int fact(int x)
{
	int f;
	f=1;
	if(x==0)
	return 0;
	else
	f=f*fact(x-1);	
}
