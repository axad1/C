#include<iostream>
using namespace std;
int main()
{	int n[5],f[5];
	int i;
	for(i=0;i<5;i++)
	{
	cout<<"Enter number:"<<endl;
	cin>>n[i];}
	for(i=0;i<5;i++)
	{
		f[i]=1;
		f[i]=f[i]*n[i];
	}
	cout<<endl<<"Factorial is"<<endl;
	for(i=0;i<5;i++)
	{cout<<f[i]<<endl;
	}
}
