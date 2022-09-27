#include<iostream>
using namespace std;
int main()
{
	int i,j;
	char s[50];
	cout<<"Write a sentence:\t\t";
	cin>>s;
	cout<<s<<endl;
	for(i=0;s[i]!='\0';i++)
	{
		cout<<s[i];
	}
}
