#include<iostream>
using namespace std;
int main()
{
	char n[9],*i;
	int length=0;
	cout<<"Enter demical number:";
	cin>>n;
	// Now Find the length of Hexadecimal Number
  	for (i=n; *i!='\0';i++)
  	{
      length++;
    }
    cout<<length;
	
}
