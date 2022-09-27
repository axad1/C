#include<iostream>
using namespace std;
int main()
{
	int x,y;
	x=5;y=10;
	cout<<x<<endl<<y<<endl<<"After swapping"<<endl;
	x=x+y;
	y=x-y;
	x=x-y;
	cout<<x<<endl<<y;
	
}
